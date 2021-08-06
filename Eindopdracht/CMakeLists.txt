cmake_minimum_required(VERSION 3.19)
project(Eindopdracht)

set(CMAKE_CXX_STANDARD 14)

add_executable(Eindopdracht main.cpp Player.h Player.cpp Collider.h Collider.cpp Enemy.h Enemy.cpp Vector2.h Vector2.cpp DeltaTime.h DeltaTime.cpp)

include_directories(C:/SFML/include)

set(SFML_ROOT C:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Eindopdracht ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()


# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
