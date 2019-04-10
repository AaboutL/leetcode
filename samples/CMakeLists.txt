include_directories(../core/include)
#list(APPEND LIBS core)

add_executable(main_leetcode main_leetcode.cc)

add_executable(main_tmp main_tmp.cc)
target_link_libraries(main_tmp core)
