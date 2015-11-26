cmake_minimum_required(VERSION 3.3.2)

project(project64)

# Warnings as errors
# Disable C4127: Conditional expression is constant.
#
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /WX /W4 /wd4127 -DUNICODE -D_UNICODE")

set (PJ64_SRC_PATH Source/Project64)
set (N64SYS_PATH ${PJ64_SRC_PATH}/N64\ System)
set (UI_SRC_PATH ${PJ64_SRC_PATH}/User\ Interface)
set (SETTINGS_SRC_PATH ${UI_SRC_PATH}/Settings)
set (WTL_CTRL_SRC_PATH ${UI_SRC_PATH}/WTL\ Controls)

set (DBG_SRCS
  ${N64SYS_PATH}/Debugger/Debug\ Dialog.cpp
  ${N64SYS_PATH}/Debugger/Debugger\ -\ Memory\ Dump.cpp
  ${N64SYS_PATH}/Debugger/Debugger\ -\ Memory\ Search.cpp
  ${N64SYS_PATH}/Debugger/Debugger\ -\ TLB.cpp
  ${N64SYS_PATH}/Debugger/Debugger\ -\ View\ Memory.cpp
  ${N64SYS_PATH}/Debugger/Debugger.cpp
)

set (SETTINGS_SRCS
  ${SETTINGS_SRC_PATH}/Settings\ Page\ -\ Advanced\ Options.cpp
  ${SETTINGS_SRC_PATH}/Settings\ Page\ -\ Directories.cpp
  ${SETTINGS_SRC_PATH}/Settings\ Page\ -\ Game\ -\ General.cpp
  ${SETTINGS_SRC_PATH}/Settings\ Page\ -\ Game\ -\ Plugin.cpp
  ${SETTINGS_SRC_PATH}/Settings\ Page\ -\ Game\ -\ Recompiler.cpp
  ${SETTINGS_SRC_PATH}/Settings\ Page\ -\ Game\ -\ Status.cpp
  ${SETTINGS_SRC_PATH}/Settings\ Page\ -\ Game\ Browser.cpp
  ${SETTINGS_SRC_PATH}/Settings\ Page\ -\ Keyboard\ Shortcuts.cpp
  ${SETTINGS_SRC_PATH}/Settings\ Page\ -\ Options.cpp
  ${SETTINGS_SRC_PATH}/Settings\ Page\ -\ Plugin.cpp
)

set (WTL_CTRLS_SRCS
  ${WTL_CTRL_SRC_PATH}/ModifiedEditBox.cpp
  ${WTL_CTRL_SRC_PATH}/PartialGroupBox.cpp
)

set (UI_SRCS
  ${SETTINGS_SRCS}
  ${WTL_CTRLS_SRCS}
  ${UI_SRC_PATH}/Cheat\ Class\ UI.cpp
  ${UI_SRC_PATH}/Frame\ Per\ Second\ Class.cpp
  ${UI_SRC_PATH}/Gui\ Class.cpp
  ${UI_SRC_PATH}/LoggingUI.cpp
  ${UI_SRC_PATH}/Main\ Menu\ Class.cpp
  ${UI_SRC_PATH}/Menu\ Class.cpp
  ${UI_SRC_PATH}/MenuShortCuts.cpp
  ${UI_SRC_PATH}/Notification\ Class.cpp
  ${UI_SRC_PATH}/Rom\ Browser\ Class.cpp
  ${UI_SRC_PATH}/Settings\ Config.cpp
)

set (SRCS
  ${DBG_SRCS}
  ${UI_SRCS}
  ${PJ64_SRC_PATH}/AppInit.cpp
  ${PJ64_SRC_PATH}/main.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
