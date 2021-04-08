cmake_minimum_required(VERSION 3.10)

# set the project name
project(TextPoint)

# ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories(${CMAKE_SOURCE_DIR}/include) # -I flags for compiler

# source
set(PROGSRC Presenter.cpp Renderer.cpp Slide.cpp TitleSlide.cpp SectionHeaderSlide.cpp)

# define executable target prog, specify sources
add_executable(textpoint textpoint.cpp ${PROGSRC})                 
target_link_libraries(textpoint ${CURSES_LIBRARIES})

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
