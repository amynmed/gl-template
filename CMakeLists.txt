

cmake_minimum_required(VERSION 3.10)

#       Change accordingly
set(CMAKE_C_COMPILER   "C:/msys64/ucrt64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/ucrt64/bin/g++.exe")


project(template)

#       ==================================================
#       SOURCE_DIRS   ====================================
#       ==================================================

# Some sources may be irrelevant depending on the current OS
set(GLFW_SOURCE_DIR ${CMAKE_SOURCE_DIR}/include/glfw)

set(GLAD_SOURCE_DIR ${CMAKE_SOURCE_DIR}/include/glad/cmake)

#       ==================================================
#       SUBDIRECTORIES ===================================
#       ==================================================

message("GLFW Source: ${GLFW_SOURCE_DIR}")
message("GLAD Source: ${GLAD_SOURCE_DIR}")

add_subdirectory(${GLFW_SOURCE_DIR})
add_subdirectory(${GLAD_SOURCE_DIR} glad_cmake)

#       MX adds the --mx option when generating glad source files
#       it's intented for multi-context scenarios,
#       for typical cases it's best to omit the MX option.
#       ================================================____===============
#       glad_add_library(glad_gl_core_mx_46 REPRODUCIBLE MX API gl:core=4.6)
glad_add_library(glad_gl_core_mx_46 REPRODUCIBLE API gl:core=4.6)

#       ==================================================
#       ==================================================


add_executable(${PROJECT_NAME} main.cpp)

#       OpenGL
find_package(OpenGL REQUIRED)

#       =================================================    
#       INCLUDE_DIRS   ==================================
#       =================================================    

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(GLFW_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/glfw/include)

set(GLM_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/glm)


#       ==================================================
#       SOURCE_FILES =====================================
#       ==================================================

file(GLOB SOURCE_FILES ${CMAKE_SOURCE_DIR}/include/src/*.cpp )


#       ==================================================
#       TARGETS ==========================================
#       ==================================================

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR} ${GLFW_INCLUDE_DIR} ${GLM_INCLUDE_DIR})

target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC glad_gl_core_mx_46 glfw)