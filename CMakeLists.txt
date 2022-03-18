cmake_minimum_required(VERSION 3.21)
project(CS_TermProject_P2)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CSS_STANDARD_LIBRARIES}")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/appicon.rc" Customer.h Bank.cpp Bank.h Window.cpp Window.h)

add_executable(${PROJECT_NAME}
        main.cpp
        ${APP_ICON_RESOURCE_WINDOWS}
        )
