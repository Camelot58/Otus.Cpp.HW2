cmake_minimum_required(VERSION 3.2)

# Определение PATCH_VERSION для локальной сборки и сборки на travis
set(PATCH_VERSION 1)
if($ENV{TRAVIS_BUILD_NUMBER})
  set(PATCH_VERSION $ENV{TRAVIS_BUILD_NUMBER})
endif()

project(helloworld VERSION 1.0.${PATCH_VERSION})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

# Создание целей
add_executable(helloworld_app main.cpp)

add_library(helloworld_lib STATIC lib.cpp)

add_executable(helloworld_test_main test_main.cpp)

# Настройка целей

# для всех целей
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wpedantic -Wall -Wextra)

target_link_libraries(helloworld_app helloworld_lib)

target_include_directories(helloworld_test_main PRIVATE ${Boost_INCLUDE_DIR})
target_compile_definitions(helloworld_test_main PRIVATE BOOST_TEST_DYN_LINK)
target_link_libraries(helloworld_test_main 
  ${Boost_LIBRARIES}
  helloworld_lib
)

install(TARGETS helloworld_app RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT camelot58@gmail.com)

include (CPack)

enable_testing()

add_test(test_version_valid helloworld_test_main)
