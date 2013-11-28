cmake_minimum_required( VERSION 2.8 )

project( spacecrash )
file( GLOB spacecrash_SOURCES *.cpp )
add_executable( spacecrash ${spacecrash_SOURCES} )
target_link_libraries( spacecrash -lGL -lglfw -lOpenAL )