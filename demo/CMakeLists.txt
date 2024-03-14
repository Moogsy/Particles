add_executable(orbits orbits.cxx)
target_link_libraries(orbits particules)

add_executable(univers univers.cxx)
target_link_libraries(univers particules)