cmake_minimum_required(VERSION 3.24)
project(Simulare)

set(CMAKE_CXX_STANDARD 17)

add_executable(Simulare main.cpp source/pavilion.cpp headers/pavilion.h source/eveniment.cpp headers/eveniment.h source/bilet.cpp headers/bilet.h source/expozitieArta.cpp headers/expozitieArta.h source/expozitieCulinara.cpp headers/expozitieCulinara.h source/spectacol.cpp headers/spectacol.h source/evenimentCaritabil.cpp headers/evenimentCaritabil.h source/idGenerator.cpp headers/idGenerator.h source/ioStream.cpp headers/ioStream.h)
