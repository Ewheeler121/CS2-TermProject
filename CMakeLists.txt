cmake_minimum_required(VERSION 3.1)
project(CS_TermProject_P2)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CSS_STANDARD_LIBRARIES}")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/appicon.rc")

set(PROJECT_SOURCES Bank/Customer.h Bank/Customer.cpp Bank/Bank.cpp Bank/Bank.h Window.cpp Window.h Bank/Accounts/Account.cpp Bank/Accounts/Account.h)

add_executable(${PROJECT_NAME}
        main.cpp ${PROJECT_SOURCES}
        ${APP_ICON_RESOURCE_WINDOWS}
        )
