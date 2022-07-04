cmake_minimum_required(VERSION 3.15)
project(marketdata_ex)
set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)

# file(GLOB_RECURSE coinbase_robot_SOURCES src/*.cpp)
file(GLOB_RECURSE coinbase_robot_SOURCES1 src/*.h)
file(GLOB_RECURSE coinbase_robot_SOURCES2 src/*.cpp)
# file(GLOB coinbase_robot_SOURCES3 src/Helpers/Base26.h)
# file(GLOB coinbase_robot_SOURCES4 src/Helpers/Base26.cpp)
# file(GLOB coinbase_robot_SOURCES5 src/boolinq/boolinq.h)

# gat
find_package(Threads REQUIRED)
find_package(cbpro++ REQUIRED)

add_executable(coinbase_robot_ex main.cpp ${coinbase_robot_SOURCES1} ${coinbase_robot_SOURCES2})
target_link_libraries(coinbase_robot_ex PUBLIC cbpro++::cbpro++)
