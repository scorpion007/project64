cmake_minimum_required(VERSION 3.3.2)

project(project64)

# Warnings as errors
# Disable C4127: Conditional expression is constant.
#
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /wd4127")
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

set (PJ64_SRC_PATH Source/Project64)

include_directories(
  ${PJ64_SRC_PATH}
  Source
  Source/3rd\ Party
)

set (N64_SYS_SRCS
  ${PJ64_SRC_PATH}/N64\ System/Cheat\ Class.cpp
  ${PJ64_SRC_PATH}/N64\ System/Emulation\ Thread.cpp
  ${PJ64_SRC_PATH}/N64\ System/N64\ Class.cpp
  ${PJ64_SRC_PATH}/N64\ System/N64\ Rom\ Class.cpp
  ${PJ64_SRC_PATH}/N64\ System/Profiling\ Class.cpp
  ${PJ64_SRC_PATH}/N64\ System/Rom\ Information\ Class.cpp
  ${PJ64_SRC_PATH}/N64\ System/Speed\ Limitor\ Class.cpp
  ${PJ64_SRC_PATH}/N64\ System/System\ Globals.cpp
  ${PJ64_SRC_PATH}/N64\ System/C\ Core/r4300i\ Commands.cpp
  ${PJ64_SRC_PATH}/N64\ System/Debugger/Debug\ Dialog.cpp
  ${PJ64_SRC_PATH}/N64\ System/Debugger/Debugger\ -\ Memory\ Dump.cpp
  ${PJ64_SRC_PATH}/N64\ System/Debugger/Debugger\ -\ Memory\ Search.cpp
  ${PJ64_SRC_PATH}/N64\ System/Debugger/Debugger\ -\ TLB.cpp
  ${PJ64_SRC_PATH}/N64\ System/Debugger/Debugger\ -\ View\ Memory.cpp
  ${PJ64_SRC_PATH}/N64\ System/Debugger/Debugger.cpp
  ${PJ64_SRC_PATH}/N64\ System/Interpreter/Interpreter\ CPU.cpp
  ${PJ64_SRC_PATH}/N64\ System/Interpreter/Interpreter\ Ops\ 32.cpp
  ${PJ64_SRC_PATH}/N64\ System/Interpreter/Interpreter\ Ops.cpp
  ${PJ64_SRC_PATH}/N64\ System/Mips/Audio.cpp
  ${PJ64_SRC_PATH}/N64\ System/Mips/Dma.cpp
  ${PJ64_SRC_PATH}/N64\ System/Mips/Eeprom.cpp
  ${PJ64_SRC_PATH}/N64\ System/Mips/FlashRam.cpp
  ${PJ64_SRC_PATH}/N64\ System/Mips/Memory\ Labels\ Class.cpp
  ${PJ64_SRC_PATH}/N64\ System/Mips/Memory\ Virtual\ Mem.cpp
  ${PJ64_SRC_PATH}/N64\ System/Mips/Mempak.cpp
  ${PJ64_SRC_PATH}/N64\ System/Mips/Pif\ Ram.cpp
  ${PJ64_SRC_PATH}/N64\ System/Mips/Register\ Class.cpp
  ${PJ64_SRC_PATH}/N64\ System/Mips/Rumblepak.cpp
  ${PJ64_SRC_PATH}/N64\ System/Mips/Sram.cpp
  ${PJ64_SRC_PATH}/N64\ System/Mips/System\ Events.cpp
  ${PJ64_SRC_PATH}/N64\ System/Mips/System\ Timing.cpp
  ${PJ64_SRC_PATH}/N64\ System/Mips/TLB\ class.cpp
  ${PJ64_SRC_PATH}/N64\ System/Recompiler/Code\ Block.cpp
  ${PJ64_SRC_PATH}/N64\ System/Recompiler/Code\ Section.cpp
  ${PJ64_SRC_PATH}/N64\ System/Recompiler/Function\ Info.cpp
  ${PJ64_SRC_PATH}/N64\ System/Recompiler/Function\ Map\ Class.cpp
  ${PJ64_SRC_PATH}/N64\ System/Recompiler/Loop\ Analysis.cpp
  ${PJ64_SRC_PATH}/N64\ System/Recompiler/Recompiler\ Class.cpp
  ${PJ64_SRC_PATH}/N64\ System/Recompiler/Recompiler\ Memory.cpp
  ${PJ64_SRC_PATH}/N64\ System/Recompiler/Recompiler\ Ops.cpp
  ${PJ64_SRC_PATH}/N64\ System/Recompiler/Reg\ Info.cpp
  ${PJ64_SRC_PATH}/N64\ System/Recompiler/Section\ Info.cpp
  ${PJ64_SRC_PATH}/N64\ System/Recompiler/x86CodeLog.cpp
  ${PJ64_SRC_PATH}/N64\ System/Recompiler/X86ops.cpp
)

set (SETTINGS_SRCS
  ${PJ64_SRC_PATH}/Settings/Debug\ Settings.cpp
  ${PJ64_SRC_PATH}/Settings/Game\ Settings.cpp
  ${PJ64_SRC_PATH}/Settings/Gui\ Settings.cpp
  ${PJ64_SRC_PATH}/Settings/Logging\ Settings.cpp
  ${PJ64_SRC_PATH}/Settings/N64System\ Settings.cpp
  ${PJ64_SRC_PATH}/Settings/Notification\ Settings.cpp
  ${PJ64_SRC_PATH}/Settings/Recompiler\ Settings.cpp
  ${PJ64_SRC_PATH}/Settings/Setting\ Config.cpp
  ${PJ64_SRC_PATH}/Settings/Settings\ Class.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-Application.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-ApplicationIndex.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-ApplicationPath.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-Cheats.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-GameSetting.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-GameSettingIndex.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-RDBCpuType.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-RDBOnOff.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-RDBRamSize.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-RDBSaveChip.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-RDBYesNo.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-RelativePath.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-RomDatabase.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-RomDatabaseIndex.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-RomDatabaseSetting.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-SelectedDirectory.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-TempBool.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-TempNumber.cpp
  ${PJ64_SRC_PATH}/Settings/SettingType/SettingsType-TempString.cpp
)

set (UI_SRCS
  ${PJ64_SRC_PATH}/User\ Interface/Cheat\ Class\ UI.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Frame\ Per\ Second\ Class.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Gui\ Class.cpp
  ${PJ64_SRC_PATH}/User\ Interface/LoggingUI.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Main\ Menu\ Class.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Menu\ Class.cpp
  ${PJ64_SRC_PATH}/User\ Interface/MenuShortCuts.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Notification\ Class.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Rom\ Browser\ Class.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Settings\ Config.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Settings/Settings\ Page\ -\ Advanced\ Options.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Settings/Settings\ Page\ -\ Directories.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Settings/Settings\ Page\ -\ Game\ -\ General.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Settings/Settings\ Page\ -\ Game\ -\ Plugin.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Settings/Settings\ Page\ -\ Game\ -\ Recompiler.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Settings/Settings\ Page\ -\ Game\ -\ Status.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Settings/Settings\ Page\ -\ Game\ Browser.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Settings/Settings\ Page\ -\ Keyboard\ Shortcuts.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Settings/Settings\ Page\ -\ Options.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Settings/Settings\ Page\ -\ Plugin.cpp
  ${PJ64_SRC_PATH}/User\ Interface/Settings/Settings\ Page.cpp
  ${PJ64_SRC_PATH}/User\ Interface/WTL\ Controls/ModifiedEditBox.cpp
  ${PJ64_SRC_PATH}/User\ Interface/WTL\ Controls/PartialGroupBox.cpp
)

set (PLUGINS_SRCS
  ${PJ64_SRC_PATH}/Plugins/Audio\ Plugin.cpp
  ${PJ64_SRC_PATH}/Plugins/Controller\ Plugin.cpp
  ${PJ64_SRC_PATH}/Plugins/GFX\ plugin.cpp
  ${PJ64_SRC_PATH}/Plugins/Plugin\ Base.cpp
  ${PJ64_SRC_PATH}/Plugins/Plugin\ Class.cpp
  ${PJ64_SRC_PATH}/Plugins/Plugin\ List.cpp
  ${PJ64_SRC_PATH}/Plugins/RSP\ Plugin.cpp
)

set (MAIN_SRCS
  ${PJ64_SRC_PATH}/AppInit.cpp
  ${PJ64_SRC_PATH}/logging.cpp
  ${PJ64_SRC_PATH}/main.cpp
)

set (MULTILANG_SRCS
  ${PJ64_SRC_PATH}/Multilanguage/Language\ Class.cpp
  ${PJ64_SRC_PATH}/Multilanguage/LanguageSelector.cpp
)

set (THIRDPARTY_SRCS
  ${PJ64_SRC_PATH}/3rd\ Party/7zip.cpp
)

source_group ("Main" FILES ${MAIN_SRCS})
source_group ("N64 System" FILES ${N64_SYS_SRCS})
source_group ("Settings" FILES ${SETTINGS_SRCS})
source_group ("User Interface" FILES ${UI_SRCS})
source_group ("Plugins" FILES ${PLUGINS_SRCS})
source_group ("Multi Language" FILES ${MULTILANG_SRCS})
source_group ("3rd Party" FILES ${THIRDPARTY_SRCS})

set (SRCS
  ${MAIN_SRCS}
  ${N64_SYS_SRCS}
  ${SETTINGS_SRCS}
  ${UI_SRCS}
  ${PLUGINS_SRCS}
  ${MULTILANG_SRCS}
  ${THIRDPARTY_SRCS}
)

add_executable(${PROJECT_NAME} ${SRCS})
