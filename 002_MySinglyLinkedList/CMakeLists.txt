cmake_minimum_required(VERSION 3.5)

project(002_MySinglyLinkedList LANGUAGES CXX C)


set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE HEADER_FILES "./*.h" "./*.hpp")
file(GLOB_RECURSE SRC_FILES "./*.c" "./*.cc" "./*.cpp")  # 获取src/里所有的源文件
add_executable(002_MySinglyLinkedList
    ${SRC_FILES}
    ${HEADER_FILES}
    main.cpp)

install(TARGETS 002_MySinglyLinkedList
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
