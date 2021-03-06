set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER /usr/bin/arm-linux-gnueabihf-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/arm-linux-gnueabihf-g++)

set(ODROID_MIRROR_DIR $ENV{ODROID_MIRROR_DIR})
set(ODROID_H5_DIR $ENV{ODROID_H5_DIR})

set(CMAKE_FIND_ROOT_PATH ${ODROID_MIRROR_DIR}${ODROID_H5_DIR})
set(CMAKE_SYSROOT ${ODROID_MIRROR_DIR})
set(CMAKE_PREFIX_PATH ${ODROID_MIRROR_DIR})

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
