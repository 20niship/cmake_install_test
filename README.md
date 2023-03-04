# cmake_install_test

https://qiita.com/modapone/items/8f97425b6167cffc815c


## example 

```cmake 
cmake_minimum_required(VERSION 3.13)
project(main CXX)

include(FetchContent)
FetchContent_Declare(
  foolib
  GIT_REPOSITORY https://github.com/20niship/cmake_install_test.git
  GIT_TAG master
)
FetchContent_MakeAvailable(foolib)

message("#AA")
message("${FOOLIB_INCLUDE_DIR}")
message("${foolib_LIBRARIES}")

include_directories(
  ${foolib_INCLUDE_DIR}
  ${OpenCV_INCLUDE_DIR}
)
add_executable(main main.cpp)
target_link_libraries(main ${foolib_LIBRARIES} foolib)

```



c++
```cpp 
#include <foolib.hpp>

int main(){
  hello();
  my_img_show();
  return 0;
}
```


