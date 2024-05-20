#
# C++
#

enable_language(CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


#
# Boost C++ Libraries
#

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIRS})


#
# executable
#

add_executable(hash_construct_test ../src/Hash.cpp HashConstructTest.cpp)
target_link_libraries(hash_construct_test PRIVATE Boost::unit_test_framework)

add_executable(hash_chars_test ../src/Hash.cpp HashCharsTest.cpp)
target_link_libraries(hash_chars_test PRIVATE Boost::unit_test_framework)

add_executable(hash_modulus_test ../src/Hash.cpp HashModulusTest.cpp)
target_link_libraries(hash_modulus_test PRIVATE Boost::unit_test_framework)

add_executable(hash_hash_test ../src/Hash.cpp HashHashTest.cpp)
target_link_libraries(hash_hash_test PRIVATE Boost::unit_test_framework)


#
# test
#

add_test(hash_construct_test hash_construct_test)
add_test(hash_chars_test hash_chars_test)
add_test(hash_modulus_test hash_modulus_test)
add_test(hash_hash_test hash_hash_test)
