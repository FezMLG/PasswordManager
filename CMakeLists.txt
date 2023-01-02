cmake_minimum_required (VERSION 3.8)

project ("PasswordManager")

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable(PasswordManager "src/File.cpp" "src/File.h" "src/main.cpp" "src/Entry.cpp" "src/Entry.h" src/Manager.cpp src/Manager.h src/App.cpp src/App.h src/Categories.cpp src/Categories.h src/Utils.cpp src/Utils.h)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")
