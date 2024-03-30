CMAKE_MINIMUM_REQUIRED(VERSION 3.28.3 FATAL_ERROR)

PROJECT(PracticumAttestation)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

ADD_EXECUTABLE(
        PracticumAttestation src/main.cpp
        src/kr1_05.h
        src/kr1_05.cpp
)
