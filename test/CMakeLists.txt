# Créer un executable à partir de fichiers sources
add_executable(test_vec  testVec.cxx)
add_executable(test_grid testGrid.cxx)

# Fait le lien avec la bibliothèque créée précedemment
# Les entêtes sont automatiquement détectés.
target_link_libraries(test_vec particules)
target_link_libraries(test_grid particules)