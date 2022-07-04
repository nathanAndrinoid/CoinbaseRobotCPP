cmake_minimum_required(VERSION 3.15)
project(marketdata_ex)
set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)

# gat
find_package(Threads REQUIRED)
find_package(cbpro++ REQUIRED)

add_executable(coinbase_robot_ex main.cpp)
target_link_libraries(coinbase_robot_ex PUBLIC cbpro++::cbpro++)
