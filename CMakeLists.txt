cmake_minimum_required(VERSION 3.10)
project(ATM)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    src/main.cpp
    src/account.cpp
    src/transaction.cpp
)

# Add header files
set(HEADERS
    include/account.h
    include/transaction.h
)

# Create executable
add_executable(atm ${SOURCES} ${HEADERS})

# Add include directories
target_include_directories(atm PRIVATE include)
