cmake_minimum_required(VERSION 3.10)
project(SimpleServerApp)

set(CMAKE_CXX_STANDARD 11)

find_package(cpprestsdk REQUIRED)

add_executable(SimpleServerApp main.cpp
        controllers/Base/Controller.hpp
        controllers/HelloController.hpp
        controllers/GoodByeController.hpp)

target_link_libraries(SimpleServerApp PRIVATE cpprestsdk::cpprest)
