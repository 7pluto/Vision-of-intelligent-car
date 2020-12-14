# cmake needs this line
cmake_minimum_required(VERSION 3.1)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
project(qr)
find_package(OpenCV REQUIRED)
FILE(GLOB SC_FILES "*.cpp" "*.h")
add_executable(${PROJECT_NAME} ${SC_FILES} Discriminate.cpp Discriminate.h)
target_link_libraries(qr PRIVATE ${OpenCV_LIBS})
find_library(WIRINGPI_LIBRARIES NAMES wiringPi)
target_link_libraries(qr PRIVATE ${WIRINGPI_LIBRARIES})