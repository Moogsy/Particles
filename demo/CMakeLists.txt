add_executable(orbits orbits.cxx)
target_link_libraries(orbits particules)

add_executable(univers2D univers2D.cxx)
target_link_libraries(univers2D particules)

add_executable(univers3D univers3D.cxx)
target_link_libraries(univers3D particules)
