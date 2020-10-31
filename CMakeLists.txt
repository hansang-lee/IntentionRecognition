cmake_minimum_required(VERSION 3.0)

project(HumanIntentionRecognizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(
	${PROJECT_NAME}
	src/main.cpp
	src/IntentRecognizer.h
	src/IntentRecognizer.cpp
	)
