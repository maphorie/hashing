#
# C++
#

enable_language(CXX)

set(CMAKE_CXX_STANDARD 11)


#
# Boost C++ Libraries
#

set(Boost_USE_STATIC_LIBS ON)

find_package(Boost REQUIRED COMPONENTS program_options)

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})


#
# executable
#

add_executable(${PROJECT_NAME} Hash.cpp main.cpp)

target_link_libraries(${PROJECT_NAME} Boost::program_options)


#
# install
#

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION $ENV{HOME}/bin)
