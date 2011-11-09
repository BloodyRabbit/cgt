#
# Console Guitar Tuner (CGT)
# Copyright (c) 2011 by Bloody.Rabbit
#
# Author: Bloody.Rabbit
#

##############
# Initialize #
##############
SET( TARGET_NAME        "cgt-common" )
SET( TARGET_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/${TARGET_NAME}" )
SET( TARGET_SOURCE_DIR  "${PROJECT_SOURCE_DIR}/src/${TARGET_NAME}" )

SET( TARGET_INCLUDE_DIRS
     ${ALSA_INCLUDE_DIRS}
     ${FFTW3_INCLUDE_DIRS}
     "${TARGET_INCLUDE_DIR}" )

# Export the include directories
SET( ${TARGET_NAME}_INCLUDE_DIRS ${TARGET_INCLUDE_DIRS} PARENT_SCOPE )

#########
# Files #
#########
SET( INCLUDE
     "${TARGET_INCLUDE_DIR}/cgt-common.h" )
SET( SOURCE
     "" )

SET( alsa_INCLUDE
     "${TARGET_INCLUDE_DIR}/alsa/Error.h"
     "${TARGET_INCLUDE_DIR}/alsa/Error.inl"
     "${TARGET_INCLUDE_DIR}/alsa/Pcm.h"
     "${TARGET_INCLUDE_DIR}/alsa/Pcm.inl" )
SET( alsa_SOURCE
     "" )

SET( fft_INCLUDE
     "${TARGET_INCLUDE_DIR}/fft/Core.h" )
SET( fft_SOURCE
     "${TARGET_SOURCE_DIR}/fft/Core.cpp" )

SET( util_INCLUDE
     "${TARGET_INCLUDE_DIR}/util/Misc.h"
     "${TARGET_INCLUDE_DIR}/util/SafeMem.h" )
SET( util_SOURCE
     "${TARGET_SOURCE_DIR}/util/Misc.cpp" )

########################
# Setup the executable #
########################
INCLUDE_DIRECTORIES( ${TARGET_INCLUDE_DIRS} )

SOURCE_GROUP( "include"       FILES ${INCLUDE} )
SOURCE_GROUP( "include\\alsa" FILES ${alsa_INCLUDE} )
SOURCE_GROUP( "include\\fft"  FILES ${fft_INCLUDE} )
SOURCE_GROUP( "include\\util" FILES ${util_INCLUDE} )

SOURCE_GROUP( "src"       FILES ${SOURCE} )
SOURCE_GROUP( "src\\alsa" FILES ${alsa_SOURCE} )
SOURCE_GROUP( "src\\fft"  FILES ${fft_SOURCE} )
SOURCE_GROUP( "src\\util" FILES ${util_SOURCE} )

ADD_LIBRARY( "${TARGET_NAME}"
             ${INCLUDE}      ${SOURCE}
             ${alsa_INCLUDE} ${alsa_SOURCE}
             ${fft_INCLUDE}  ${fft_SOURCE}
             ${util_INCLUDE} ${util_SOURCE} )

TARGET_BUILD_PCH( "${TARGET_NAME}"
                  "${TARGET_INCLUDE_DIR}/cgt.h"
                  "${TARGET_SOURCE_DIR}/cgt.cpp" )
TARGET_LINK_LIBRARIES( "${TARGET_NAME}"
                       ${ALSA_LIBRARIES}
                       ${FFTW3_LIBRARIES} )