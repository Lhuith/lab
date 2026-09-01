cmake_minimum_required(VERSION 3.22.1)

project(test) #project name
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(BUILD_SHARED_LIBS ON)

add_executable(${PROJECT_NAME} main.cpp)

# find_package(glfw3 REQUIRED) #assuming you installed it somwhere
target_include_directories(${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/../Libs/glm 
    PRIVATE ${PROJECT_SOURCE_DIR}/../Libs/GLFW/include
    PRIVATE ${PROJECT_SOURCE_DIR}/../Libs/GLEW/include
)

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
	message("You're on Mac OS !")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set(CMAKE_EXE_LINKER_FLAGS "-lGL")

target_link_libraries(
    ${PROJECT_NAME} 
        ${PROJECT_SOURCE_DIR}/../Libs/GLFW/lib-mingw-w64/libglfw3.a glfw
        ${PROJECT_SOURCE_DIR}/../Libs/GLEW/lib/Release/libGLEW.a GLEW
    )
	message("You're on Linux, using libXXX.a!")
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
# https://stackoverflow.com/questions/4702732/the-program-cant-start-because-libgcc-s-dw2-1-dll-is-missing
# gilgamesh smiles upon you hardmath
add_definitions("-DGLEW_STATIC")
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")

#! not sure if this 
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

target_link_libraries(
    ${PROJECT_NAME} 
        ${PROJECT_SOURCE_DIR}/../Libs/GLFW/lib-mingw-w64/libglfw3.a
        ${PROJECT_SOURCE_DIR}/../Libs/GLEW/lib/Release/libGLEW.a
        ${PROJECT_SOURCE_DIR}/../Libs/GLEW/lib/Release/Win32/glew32s.lib
        gdi32
        opengl32
    )
	message("You're on Windows !")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

# windows link
