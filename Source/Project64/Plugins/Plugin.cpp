/****************************************************************************
*                                                                           *
* Project 64 - A Nintendo 64 emulator.                                      *
* http://www.pj64-emu.com/                                                  *
* Copyright (C) 2012 Project64. All rights reserved.                        *
*                                                                           *
* License:                                                                  *
* GNU/GPLv2 http://www.gnu.org/licenses/gpl-2.0.html                        *
*                                                                           *
****************************************************************************/
#include "stdafx.h"

void FixUPXIssue(BYTE * ProgramLocation);

CPlugin::CPlugin() :
	m_hDll(NULL),	
	m_Initilized(false), 
	m_RomOpen(false),
	RomOpen(NULL),
	RomClosed(NULL),
	CloseDLL(NULL),
	PluginLoaded(NULL),
	DllConfig(NULL),
	SetSettingInfo(NULL),
	SetSettingInfo2(NULL),
	SetSettingInfo3(NULL)
{
	memset(&m_PluginInfo, 0, sizeof(m_PluginInfo));
}

bool CPlugin::Init(const char * FileName)
{
	// Already loaded, so unload first.
	if (m_hDll != NULL)
		UnloadPlugin();

	// Try to load the plugin DLL
	UINT LastErrorMode = SetErrorMode(SEM_FAILCRITICALERRORS);
	m_hDll = LoadLibrary(FileName);
	SetErrorMode(LastErrorMode);
	
	if (m_hDll == NULL)
		return false;

	FixUPXIssue((BYTE *)m_hDll);

	// Get DLL information
	void (__cdecl *GetDllInfo) (PLUGIN_INFO * PluginInfo);
	LoadFunction(GetDllInfo);
	if (GetDllInfo == NULL) 
		return false;

	GetDllInfo(&m_PluginInfo);
	if (!CPluginList::ValidPluginVersion(m_PluginInfo)) 
		return false;

	LoadFunction(CloseDLL);
	LoadFunction(RomOpen);
	LoadFunction(RomClosed);
	LoadFunction(DllConfig);

	if (CloseDLL == NULL
		|| RomOpen == NULL
		|| RomClosed == NULL)
		return false;

	// GFX: version 0x104, audio: version 0x102
	LoadFunction(PluginLoaded);

	LoadFunction(SetSettingInfo3);
	LoadFunction(SetSettingInfo2);
	LoadFunction(SetSettingInfo);

	if (SetSettingInfo3)
	{
		PLUGIN_SETTINGS3 info;
		info.FlushSettings = (void (*)(void *))&CSettings::FlushSettings;
		SetSettingInfo3(&info);
	}

	if (SetSettingInfo2)
	{
		PLUGIN_SETTINGS2 info;
		info.FindSystemSettingId = (unsigned int (*)(void *, const char *))&CSettings::FindSetting;
		SetSettingInfo2(&info);
	}

	if (SetSettingInfo)
	{
		PLUGIN_SETTINGS info;
		info.dwSize = sizeof(PLUGIN_SETTINGS);
		info.DefaultStartRange = GetDefaultSettingStartRange();
		info.SettingStartRange = GetSettingStartRange();
		info.MaximumSettings   = MaxPluginSetting;
		info.NoDefault         = Default_None;
		info.DefaultLocation   = g_Settings->LoadDword(Setting_UseFromRegistry) ? SettingType_Registry : SettingType_CfgFile;
		info.handle            = g_Settings;
		info.RegisterSetting   = (void (*)(void *, int, int, SettingDataType, SettingType, const char *, const char *, DWORD))&CSettings::RegisterSetting;
		info.GetSetting        = (unsigned int (*)(void *, int))&CSettings::GetSetting;
		info.GetSettingSz      = (const char * (*)(void *, int, char *, int ))&CSettings::GetSettingSz;
		info.SetSetting        = (void (*)(void *,int,unsigned int))&CSettings::SetSetting;
		info.SetSettingSz      = (void (*)(void *,int,const char *))&CSettings::SetSettingSz;
		info.UseUnregisteredSetting = NULL;

		SetSettingInfo(&info);
//		g_Settings->UnknownSetting_GFX = info.UseUnregisteredSetting;
	}

	return true;
}

void CPlugin::RomOpened()
{
	if (m_RomOpen 
		|| RomOpen == NULL)
		return;

	RomOpen();
	m_RomOpen = true;
}

void CPlugin::RomClose()
{
	if (!m_RomOpen)
		return;

	RomClosed();
	m_RomOpen = false;
}

void CPlugin::GameReset()
{
	if (!m_RomOpen)
		return;

	RomClosed();
	RomOpen();
}

void CPlugin::Close()
{
	RomClose();

	if (m_Initilized)
	{
		CloseDLL();
		m_Initilized = false;
	}
}

void CPlugin::UnloadPlugin()
{
	memset(&m_PluginInfo, 0, sizeof(m_PluginInfo));
	if (m_hDll != NULL)
	{
		FreeLibrary((HMODULE)m_hDll);
		m_hDll = NULL;
	}

//	DllAbout		= NULL;
	CloseDLL		= NULL;
	RomOpen			= NULL;
	RomClosed		= NULL;
	PluginLoaded	= NULL;
	DllConfig		= NULL;
	SetSettingInfo	= NULL;
	SetSettingInfo2 = NULL;
	SetSettingInfo3 = NULL;
}

CPlugin::~CPlugin()
{
	// NOTE: Unless the cleanup code is changed, we need to reimplement this in each derived plugin class
	// as the object most likely will have changed at this point, and refer to CPlugin's vtable rather than
	// the derived plugin class' vtable.
#if 0
	Close();
	UnloadPlugin();
#endif
}