cmake_minimum_required(VERSION 3.9)

project(RenderBuddy)

file(GLOB dot_cpp *.cpp)
file(GLOB dot_h *.h)

add_executable(render_buddy ${dot_cpp} ${dot_h})