cmake_minimum_required(VERSION 2.8.3)
project(zbarQR)
set(CMAKE_MODULE_PATH ${ZBARCV_SOURCE_DIR})
find_package (OpenCV)
find_package(catkin REQUIRED COMPONENTS
  cv_bridge##ros的数据转化成opencv数据,再用opencv处理
  image_transport
  roscpp
  sensor_msgs
  std_msgs
)
 
find_package(PkgConfig)
pkg_check_modules(PC_ZBAR QUIET zbar)
set(ZBAR_DEFINITIONS ${PC_ZBAR_CFLAGS_OTHER})
find_library(ZBAR_LIBRARIES NAMES zbar
             HINTS ${PC_ZBAR_LIBDIR} ${PC_ZBAR_LIBRARY_DIRS} )
find_path(ZBAR_INCLUDE_DIR Decoder.h
          HINTS ${PC_ZBAR_INCLUDEDIR} ${PC_ZBAR_INCLUDE_DIRS}
          PATH_SUFFIXES zbar )
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(ZBAR  DEFAULT_MSG  ZBAR_LIBRARIES ZBAR_INCLUDE_DIR)
catkin_package(
 INCLUDE_DIRS include
  LIBRARIES zbarQR
)
include_directories(
    include
  ${catkin_INCLUDE_DIRS}
)
 
add_executable(zbarQR src/zbarQR.cpp)
target_link_libraries(zbarQR
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
  ${Boost_LIBRARIES}
 # ${Zbar_LIBRARIES}
  /usr/lib/libzbar.so##最重要的添加编译用的共享库
 
)
 
add_executable(zbar_sub src/zbar_sub.cpp)
target_link_libraries(zbar_sub
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}

 # ${Zbar_LIBRARIES}
  /usr/lib/libzbar.so##最重要的添加编译用的共享库
 
)
 
add_executable(zbar_sub2 src/zbar_sub2.cpp)
target_link_libraries(zbar_sub2
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
  ${Boost_LIBRARIES}
 # ${Zbar_LIBRARIES}
  /usr/lib/libzbar.so##最重要的添加编译用的共享库
 
)
