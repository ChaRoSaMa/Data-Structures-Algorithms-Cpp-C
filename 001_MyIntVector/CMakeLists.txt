cmake_minimum_required(VERSION 3.5)

project(001_MyIntVector LANGUAGES CXX C)



set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE HEADER_FILES "./*.h" "./*.hpp")
file(GLOB_RECURSE SRC_FILES "./*.c" "./*.cc")  # 获取src/里所有的源文件
add_executable(001_MyIntVector
    ${SRC_FILES}
    ${HEADER_FILES}
    main.cpp)

install(TARGETS 001_MyIntVector
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
