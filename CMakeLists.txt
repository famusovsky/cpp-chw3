cmake_minimum_required(VERSION 3.16)
project(chw3)

add_subdirectory(checker)
add_subdirectory(for_time_measure)
add_subdirectory(task_execution)

add_executable(main
  main.cpp
)

target_link_libraries(main
  checker_lib
  for_time_measure_lib
  task_execution_lib
)
