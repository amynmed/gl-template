

cmake_minimum_required(VERSION 3.10)

project(renderer)


add_executable(${PROJECT_NAME} main.cpp)

#       OpenGL
find_package(OpenGL REQUIRED)

#       =================================================    
#       INCLUDE_DIRS   ==================================
#       =================================================    

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(GLFW_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/glfw/include)

set(GLM_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/glm/include)

#       ==================================================
#       SOURCE_DIRS   ====================================
#       ==================================================

# Some sources are irrelevant depending on the current OS
set(GLFW_SOURCE_DIR ${CMAKE_SOURCE_DIR}/include/glfw/src)

set(GLAD_SOURCE_DIR ${CMAKE_SOURCE_DIR}/include/glad)

#       ==================================================
#       SUBDIRECTORIES ===================================
#       ==================================================

add_subdirectory(GLFW_SOURCE_DIR)
add_subdirectory(GLAD_SOURCE_DIR)

#       ==================================================
#       SOURCE_FILES =====================================
#       ==================================================

file(GLOB SOURCE_FILES ${CMAKE_SOURCE_DIR}/include/src/*.cpp )


#       ==================================================
#       TARGETS ==========================================
#       ==================================================

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR} ${GLFW_INCLUDE_DIR} ${GLM_INCLUDE_DIR})

target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE glad glfw)

#target_link_directories(${PROJECT_NAME} PRIVATE ${LIB_DIRS})







