# cmake_minimum_required(VERSION <specify CMake version here>)
project(proiect)

set(CMAKE_CXX_STANDARD 14)

add_executable(proiect main.cpp model/Film.cpp model/Scurtmetraj.cpp model/headers/Scurtmetraj.h model/Serial.cpp model/headers/Serial.h model/headers/Film.h controller/Vector.cpp controller/headers/Vector.h controller/List.cpp controller/headers/List.h controller/Set.cpp controller/headers/Set.h controller/Map.cpp controller/headers/Map.h view/UI.cpp view/headers/UI.h controller/Controller.cpp controller/headers/Controller.h model/Jpeg.cpp model/headers/Jpeg.h model/headers/Png.h model/Imagine.cpp model/headers/Imagine.h model/Png.cpp)