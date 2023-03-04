cmake_minimum_required(VERSION 3.13)
project(foolib CXX)
find_package(OpenCV REQUIRED)
include_directories(
  ${PROJECT_SRC_DIR}
  ${OpenCV_INCLUDE_DIR}
)
add_library(foolib STATIC src/lib.cpp )
target_link_libraries(foolib 
  ${OpenCV_LIBRARIES}
)

# バイナリ: 引数3個目にRUNTIMEを指定する。
# INSTALL(TARGETS lan_router RUNTIME DESTINATION bin)
# ライブラリ: 引数3個目にLIBRARY を指定する。
INSTALL(TARGETS foolib LIBRARY DESTINATION lib)
# それ以外(スクリプトやconfファイル): 引数1個目にFILESを指定する。
# INSTALL(FILES lan_interface.conf DESTINATION conf PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)

