include_directories(../core/include)
#list(APPEND LIBS core)

add_executable(main_leetcode main_leetcode.cc)

add_executable(main_tmp main_linklist.cc)
target_link_libraries(main_tmp core)

add_executable(main_stackqueueheap main_stackqueueheap.cc)

add_executable(main_greedy main_greedy.cpp)

add_executable(main_recursion_iteration main_recursion_backtracking.cpp)

add_executable(reverse_linklist reverse_linklist.cc)