#---------------------------------------#
#				SETUP					#
#---------------------------------------#
cmake_minimum_required(VERSION 3.30.0 FATAL_ERROR)

project(KLOGGER VERSION 1.0.0 LANGUAGES CXX)



# --------------------------------------- #
#              FIND PACKAGES              #
# --------------------------------------- #
add_subdirectory(Libs)

# Output directories
set(OUTPUT_DIR_BASE "${CMAKE_SOURCE_DIR}/Builds/${CMAKE_CXX_COMPILER_ID}")

message(STATUS "[${PROJECT_NAME}]: Base output directory: ${OUTPUT_DIR_BASE}")

# Use generator expressions directly in output variables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR_BASE}/$<CONFIG>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR_BASE}/$<CONFIG>/libs")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR_BASE}/$<CONFIG>/libs")


# Define output build folder
set(KLOGGER_OUTPUT_DIR "${CMAKE_SOURCE_DIR}/Builds/${CMAKE_CXX_COMPILER_ID}_$<CONFIG>")

# Define Output Build path for libraries & executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${KLOGGER_OUTPUT_DIR}/Libs")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${KLOGGER_OUTPUT_DIR}/Libs")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${KLOGGER_OUTPUT_DIR}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



#---------------------------------------#
#				SOURCES					#
#---------------------------------------#
file(GLOB_RECURSE KLOGGER_SOURCES "Code/Source/*.cpp")



#---------------------------------------#
#				BUILD MODE  			#
#---------------------------------------#
option(KLOGGER_BUILD_STATIC "Build static libraries" ON)

if(KLOGGER_BUILD_STATIC)
    add_library(KLOGGER STATIC ${KLOGGER_SOURCES})
else()
    add_library(KLOGGER SHARED ${KLOGGER_SOURCES})
endif()



#---------------------------------------#
#                INCLUDE                #
#---------------------------------------#
target_include_directories(KLOGGER PUBLIC "Code/Include")



#---------------------------------------#
#                COMPILE MODE           #
#---------------------------------------#
target_compile_features(KLOGGER PUBLIC cxx_std_20)

if (MSVC)
    set(CMAKE_DEBUG_POSTFIX "d")
    target_compile_options(KLOGGER PUBLIC /W3 /WX)
else ()
    target_compile_options(KLOGGER PUBLIC -Wall -Wextra -Wpedantic -Werror)
endif ()

# Build position independent code.
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Disable C and C++ compiler extensions.
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



#---------------------------------------#
#        EXPORTS / IMPORTS FOR LIB      #
#---------------------------------------#
# Disable lib prefix
set_target_properties(KLOGGER PROPERTIES PREFIX "")

# Set dll name
set_target_properties(KLOGGER PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-${PROJECT_VERSION}")



#---------------------------------------#
#               LINK LIBRARIES          #
#---------------------------------------#
target_link_libraries(KLOGGER PUBLIC fmt::fmt)

option(BUILD_EXECUTABLE "Build an executable to live debug the logger" ON)

if (BUILD_EXECUTABLE)
    add_subdirectory(Test)
endif ()