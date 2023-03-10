cmake_minimum_required(VERSION 3.13)
project(foolib CXX)
find_package(OpenCV REQUIRED)
add_library(foolib STATIC src/foolib.cpp )
target_link_libraries(foolib 
  ${OpenCV_LIBRARIES}
)
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${OpenCV_INCLUDE_DIR}
)

include(CMakePackageConfigHelpers)
target_include_directories(foolib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    $<INSTALL_INTERFACE:include>)

# バイナリ: 引数3個目にRUNTIMEを指定する。
# INSTALL(TARGETS lan_router RUNTIME DESTINATION bin)
# ライブラリ: 引数3個目にLIBRARY を指定する。
INSTALL(TARGETS foolib LIBRARY DESTINATION lib)
# それ以外(スクリプトやconfファイル): 引数1個目にFILESを指定する。
# INSTALL(FILES lan_interface.conf DESTINATION conf PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)
install(TARGETS foolib EXPORT foolib-config)

install(EXPORT foolib-config
    NAMESPACE foolib::
    DESTINATION lib/cmake/foolib)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/  DESTINATION include)
