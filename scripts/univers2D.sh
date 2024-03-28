#!/bin/bash

cd ..

cd build || exit

make

if [ $? -ne 0 ]; then
    echo "Erreur lors de l'exécution de make"
    exit 1
fi

./demo/univers2D > ../simulation_files/output.txt

if [ $? -ne 0 ]; then
    echo "Erreur lors de l'exécution de ./orbits"
    exit 1
fi

cd ../simulation_files

gnuplot stromer2D.plot 

if [ $? -ne 0 ]; then
    echo "Erreur lors de l'exécution de gnuplot"
    exit 1
fi

xdg-open stromer.gif

echo "Script terminé avec succès."
