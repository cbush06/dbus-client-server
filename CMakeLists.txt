########################################
#      GLOBAL CMAKE CONFIGURATION      #
########################################
cmake_minimum_required(VERSION 3.10.2)
project(dbus_client_server)
set(CMAKE_BUILD_TYPE Debug)
add_definitions("-std=c++17")

########################################
#        SET PROJECT VARIABLES         #
########################################
set(DBUS_SCHEMAS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dbus_schemas)
set(INCLUDES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/includes)
set(DBUS_SCHEMA_SRCS
    ${DBUS_SCHEMAS_DIR}/concatenator-client.h
    ${DBUS_SCHEMAS_DIR}/concatenator-server.h)
set(HEADER_SRCS
    ${INCLUDES_DIR}/Concatenator.h)
message(STATUS "DBUS_SCHEMAS_DIR=" ${DBUS_SCHEMAS_DIR})
message(STATUS "INCLUDES_DIR=" ${INCLUDES_DIR})

########################################
#      INCLUDE CONAN DEPENDENCIES      #
########################################
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

########################################
#      INCLUDE OTHER DEPENDENCIES      #
########################################
find_library(SDBUS_LIBS sdbus-c++)
message(STATUS "SDBUS_LIBS=${SDBUS_LIBS}")

########################################
#     GENERATE DBUS FILES FROM XML     #
########################################
find_program(SDBUS_XML_2_CPP sdbuscpp-xml2cpp REQUIRED)
message(STATUS "Running ${SDBUS_XML_2_CPP}")
execute_process(
    COMMAND ${SDBUS_XML_2_CPP} concatenator_schema.xml --adaptor=concatenator-server.h --proxy=concatenator-client.h
    WORKING_DIRECTORY ${DBUS_SCHEMAS_DIR}
    OUTPUT_VARIABLE XML2CPP_OUTPUT
    RESULT_VARIABLE XML2CPP_RESULT
)
message(STATUS "XML2CPP_OUTPUT=" ${XML2CPP_OUTPUT})

########################################
#      OUTPUT FINAL EXECUTABLE(S)      #
########################################
add_executable(dbus_server main_concatenator.cpp Concatenator.cpp ${HEADER_SRCS} ${DBUS_SCHEMA_SRCS})
target_include_directories(dbus_server PUBLIC ${DBUS_SCHEMAS_DIR} ${INCLUDES_DIR})
target_link_libraries(dbus_server ${SDBUS_LIBS} ${CONAN_LIBS})
