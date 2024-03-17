#!/bin/bash

cd build || exit

make

if [ $? -ne 0 ]; then
    echo "Erreur lors de l'exécution de make"
    exit 1
fi

./demo/orbits > ../output.txt

if [ $? -ne 0 ]; then
    echo "Erreur lors de l'exécution de ./orbits"
    exit 1
fi

cd ..

gnuplot stromer.plot 

if [ $? -ne 0 ]; then
    echo "Erreur lors de l'exécution de gnuplot"
    exit 1
fi

xdg-open stromer.gif

echo "Script terminé avec succès."
