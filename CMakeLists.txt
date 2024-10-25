# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(Project_Bank VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the 'Include' directory for project headers (login.h)
include_directories(${PROJECT_SOURCE_DIR}/Include)

# Add the 'json/include' directory for nlohmann JSON library
include_directories(${PROJECT_SOURCE_DIR}/json/include)

# Add executable (main.cpp and login.cpp in 'src' folder)
add_executable(Project_Bank 
    main.cpp 
    src/login.cpp
    src/MilesAccount.cpp
    src/savingAccount.cpp
    src/customer.cpp
)

# Specify the output directory for the .exe file
set_target_properties(Project_Bank PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Target the 'Include' directory and 'json/include' for headers
target_include_directories(Project_Bank PUBLIC 
    ${PROJECT_SOURCE_DIR}/Include 
    ${PROJECT_SOURCE_DIR}/json/include
)
