#----------------------------------------------#
#-----Konfiguration des Buildsystems CMake-----#
#----------------------------------------------#

# Minimale Version des Buildsystems
cmake_minimum_required(VERSION 3.16)
# Name des Projekts
project(ProjectAlpha)

#----------------------------------------------#
#-------------------Optionen-------------------#
#----------------------------------------------#

# Setzte verwendeten C++-Standard auf C++17
set(CMAKE_CXX_STANDARD 17)
# Optional: Baue mit Debugsymbolen / Optimierung
set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE Release)
# Optional: Prüfe alle Targets auf Speicherlecks
# add_compile_options(-fsanitize=address)
# add_link_options(-fsanitize=address)

# Füge Includeverzeichnisse hinzu
include_directories(include)
include_directories(external)


#----------------------------------------------#
#---------------Erzeuge Projekt----------------#
#----------------------------------------------#

# Baue das Programm 'linkedListMain' aus den Quellen
# examples/linkedList
add_executable(linkedListMain
        examples/linkedList/main.cpp
        )

# Baue das Programm 'priorityQueueMain' aus den Quellen
# examples/priorityQueue
 add_executable(priorityQueueMain
        examples/priorityQueue/main.cpp
        )

# Baue das Programm 'queueMain' aus den Quellen
# examples/queue
add_executable(queueMain
        examples/queue/main.cpp
        )

# Baue das Programm `stackMain' aus den Quellen
# examples/stack
add_executable(stackMain
        examples/stack/main.cpp
        )

# Baue das Programm `unorderedStackMain' aus den Quellen
# examples/unorderedSet
add_executable(unorderedSetMain
        examples/unorderedSet/main.cpp
        )

#----------------------------------------------#
#----------Download and use GoogleTest---------#
#----------------------------------------------#

# Use CMakes FetchContent
include(FetchContent)
# Workaround for CMake >= 3.24
# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif()

# Download GoogleTest (we use version 1.12.1)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# Workaround for Windows:
# Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Include CMake configuration of GoogleTest
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Enable GoogleTest
enable_testing()

#----------------------------------------------#
#-------------Erzeuge Testprogramme------------#
#----------------------------------------------#

# Declare test program singlyLinkedList_test
add_executable(singlyLinkedList_test tests/linkedList/singlyLinkedList_test.cpp)
target_link_libraries(singlyLinkedList_test GTest::gtest_main)
gtest_discover_tests(singlyLinkedList_test)

# Declare test program doublyLinkedList_test
add_executable(doublyLinkedList_test tests/linkedList/doublyLinkedList_test.cpp)
target_link_libraries(doublyLinkedList_test GTest::gtest_main)
gtest_discover_tests(doublyLinkedList_test)
# Declare test program doublyLinkedList_speedtest
add_executable(doublyLinkedList_speedtest tests/linkedList/doublyLinkedList_speedtest.cpp)

# Declare test program queue_test
add_executable(queue_test tests/queue/queue_test.cpp)
target_link_libraries(queue_test GTest::gtest_main)
gtest_discover_tests(queue_test)

# Declare test program stack_test
add_executable(stack_test tests/stack/stack_test.cpp)
target_link_libraries(stack_test GTest::gtest_main)
gtest_discover_tests(stack_test)
# Declare test program stack_speedtest
add_executable(stack_speedtest tests/stack/stack_speedtest.cpp)

# Declare test program priorityQueue_test
add_executable(priorityQueue_test tests/priorityQueue/priorityQueue_test.cpp)
target_link_libraries(priorityQueue_test GTest::gtest_main)
gtest_discover_tests(priorityQueue_test)
# Declare test program priorityQueue_speedtest
add_executable(priorityQueue_speedtest tests/priorityQueue/priorityQueue_speedtest.cpp)