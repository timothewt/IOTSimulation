cmake_minimum_required(VERSION 3.23)
project(ProjetIOT)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../src")

add_executable(ProjetIOT
        src/Server/Server.cpp src/Server/Server.hpp
        src/Scheduler/Scheduler.cpp src/Scheduler/Scheduler.hpp
        src/Sensors/Sensor.cpp src/Sensors/Sensor.hpp
        src/Sensors/Temperature.cpp src/Sensors/Temperature.hpp
        src/Sensors/Humidity.cpp src/Sensors/Humidity.hpp
        src/Sensors/Light.cpp src/Sensors/Light.hpp
        src/Sensors/Pressure.cpp src/Sensors/Pressure.hpp
        src/Scheduler/Clock.cpp src/Scheduler/Clock.hpp
        src/Plane.cpp src/Plane.hpp
        src/main.cpp)