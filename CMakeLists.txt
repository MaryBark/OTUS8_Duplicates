cmake_minimum_required(VERSION 3.2)

project(OTUS8_Duplicates VERSION 0.0.${PATCH_VERSION})

configure_file(version.h.in version.h)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(Boost_USE_STATIC_LIBS ON) # 1/ вкл.чаем boost!!!!!!
set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread -fno-omit-frame-pointer")

add_compile_options(-Wall -Wextra -pedantic -Werror)

# ищем пакеты для него
find_package(Boost COMPONENTS unit_test_framework program_options filesystem regex REQUIRED)
find_package(Threads REQUIRED)

add_library(Balks Balk.h Balk.cpp ResponseHandler.h ResponseHandler.cpp)

add_library(async Ansynchon.h Ansynchon.cpp)
# без подключения этих потоков не получается !!!!! аааааааааа
target_link_libraries(async Balks Threads::Threads)

add_executable(OTUS8_Duplicates main.cpp)
set_target_properties(OTUS8_Duplicates PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )

#set_target_properties(OTUS8_Duplicates PROPERTIES
#        CXX_STANDARD 17
#        CXX_STANDARD_REQUIRED ON
#        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
#        )

target_link_libraries(OTUS8_Duplicates ${Boost_LIBRARIES} Balks async)

# а вот так было лучше!!!!!
#add_executable(OTUS8_Duplicates main.cpp Ansynchon.h Ansynchon.cpp Balk.h Balk.cpp ResponseHandler.h ResponseHandler.cpp)


# запихиваем в свойства
#set_target_properties(OTUS8_Duplicates PROPERTIES
#        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
#        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
#        )

#set_target_properties(OTUS8_Duplicates PROPERTIES
#        CXX_STANDARD 17
#        CXX_STANDARD_REQUIRED ON
#        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
#        )

#    set_target_properties(OTUS8_Duplicates PROPERTIES
#            INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})

install(TARGETS OTUS8_Duplicates RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT Alttaira@yandex.ru)

include(CPack)
