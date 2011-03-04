# - this module looks for Matlab
# Defines:
#  MATLAB_ROOT:        root matlab directory
#  MATLAB_BIN_DIR:     matlab binaries directory
#  MATLAB_INCLUDE_DIR: include path for mex.h, engine.h
#  MATLAB_RUNTIME_DIR: matlab runtime directory
#  MATLAB_LIB_DIR:     matlab libraries directory

#  MATLAB_MEX_LIBRARY: path to libmex.lib
#  MATLAB_MX_LIBRARY:  path to libmx.lib
#  MATLAB_ENG_LIBRARY: path to libeng.lib
#  MATLAB_MCR_LIBRARY: path to libmwmclmcrrt.lib

#=============================================================================
# Copyright 2011 Mathias Gaunard
#=============================================================================

SET(MATLAB_FOUND 0)

IF(NOT MATLAB_ROOT AND NOT $ENV{MATLAB_ROOT} STREQUAL "")
  SET(MATLAB_ROOT $ENV{MATLAB_ROOT})
ENDIF(NOT MATLAB_ROOT AND NOT $ENV{MATLAB_ROOT} STREQUAL "")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  IF(CMAKE_SIZEOF_VOID_P EQUAL 4)
    SET(MATLAB_ARCH maci)
  ELSE(CMAKE_SIZEOF_VOID_P EQUAL 4)
    SET(MATLAB_ARCH maci64)
  ENDIF(CMAKE_SIZEOF_VOID_P EQUAL 4)
ELSE(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  IF(CMAKE_SIZEOF_VOID_P EQUAL 4)
    SET(MATLAB_ARCH glnx86)
  ELSE(CMAKE_SIZEOF_VOID_P EQUAL 4)
    SET(MATLAB_ARCH glnxa64)
  ENDIF(CMAKE_SIZEOF_VOID_P EQUAL 4)  
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

IF(WIN32)

  IF(NOT MATLAB_ROOT)
    GET_FILENAME_COMPONENT(
      MATLAB_ROOT "[HKEY_LOCAL_MACHINE\\SOFTWARE\\MathWorks\\MATLAB\\7.0;MATLABROOT]"
      ABSOLUTE
    )
    IF(NOT IS_DIRECTORY MATLAB_ROOT)
      SET(MATLAB_ROOT)
    ENDIF(NOT IS_DIRECTORY MATLAB_ROOT)
  ENDIF(NOT MATLAB_ROOT)

  IF(${CMAKE_GENERATOR} MATCHES "Visual Studio 6")
    SET(MATLAB_LIB_DIR "${MATLAB_ROOT}/extern/lib/win32/microsoft/msvc60")
  ELSEIF(${CMAKE_GENERATOR} MATCHES "Visual Studio 7")
    # Assume people are generally using 7.1,
    # if using 7.0 need to link to: ../extern/lib/win32/microsoft/msvc70
   SET(MATLAB_LIB_DIR "${MATLAB_ROOT}/extern/lib/win32/microsoft/msvc71")
  ELSEIF(${CMAKE_GENERATOR} MATCHES "Borland")
    # Same here, there are also: bcc50 and bcc51 directories
    SET(MATLAB_LIB_DIR "${MATLAB_ROOT}/extern/lib/win32/microsoft/bcc54")
  ELSE()
    IF(MATLAB_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Generator not compatible: ${CMAKE_GENERATOR}")
    ENDIF(MATLAB_FIND_REQUIRED)
  ENDIF()

ENDIF(WIN32)

IF(NOT MATLAB_ROOT)
  # Search in the following directories for a directory that contains
  # the name 'matlab' case-insensitively.
  SET(DIRECTORIES /usr/local /opt $ENV{HOME} /Applications)

  FOREACH(DIR ${DIRECTORIES})
    FILE(GLOB NAMES "${DIR}/*[mM][aA][tT][lL][aA][bB]*")
    FOREACH(NA ${NAMES})
      IF( IS_DIRECTORY ${NA}
      AND IS_DIRECTORY "${NA}/bin"
      AND IS_DIRECTORY "${NA}/runtime"
      AND IS_DIRECTORY "${NA}/toolbox" )
        SET(MATLAB_ROOT ${NA})
      ENDIF()
    ENDFOREACH()
  ENDFOREACH()    
ENDIF(NOT MATLAB_ROOT)

IF(NOT MATLAB_ROOT AND MATLAB_FIND_REQUIRED)
  MESSAGE(FATAL_ERROR "Matlab root not found")
ELSEIF(MATLAB_ROOT)
  SET(MATLAB_FOUND 1)
ENDIF(NOT MATLAB_ROOT AND MATLAB_FIND_REQUIRED)

IF(MATLAB_ROOT)
  SET(MATLAB_BIN_DIR "${MATLAB_ROOT}/bin")
ENDIF(MATLAB_ROOT)

IF(MATLAB_ROOT AND NOT MATLAB_LIB_DIR)
  SET(MATLAB_LIB_DIR "${MATLAB_ROOT}/bin/${MATLAB_ARCH}")
ENDIF(MATLAB_ROOT AND NOT MATLAB_LIB_DIR)

IF(MATLAB_ROOT AND NOT MATLAB_RUNTIME_DIR)
  SET(MATLAB_RUNTIME_DIR "${MATLAB_ROOT}/runtime/${MATLAB_ARCH}")
ENDIF(MATLAB_ROOT AND NOT MATLAB_RUNTIME_DIR)

FIND_PATH(MATLAB_INCLUDE_DIR
  "mex.h"
  "${MATLAB_ROOT}/extern/include"
)

FIND_LIBRARY(MATLAB_MEX_LIBRARY
  mex
  ${MATLAB_LIB_DIR}
)
FIND_LIBRARY(MATLAB_MX_LIBRARY
  mx
  ${MATLAB_LIB_DIR}
)
FIND_LIBRARY(MATLAB_ENG_LIBRARY
  eng
  ${MATLAB_LIB_DIR}
)
FIND_LIBRARY(MATLAB_MCR_LIBRARY
  mwmclmcrrt
  ${MATLAB_RUNTIME_DIR}
)

MARK_AS_ADVANCED(
  MATLAB_FOUND
  MATLAB_ROOT
  MATLAB_INCLUDE_DIR
  MATLAB_BIN_DIR
  MATLAB_LIB_DIR
  MATLAB_RUNTIME_DIR
  MATLAB_MEX_LIBRARY
  MATLAB_MX_LIBRARY
  MATLAB_ENG_LIBRARY
  MATLAB_MCR_LIBRARY
)
