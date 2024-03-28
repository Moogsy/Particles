#!/usr/bin/gnuplot
set terminal gif animate delay 10
set output "stromer.gif"
stats "output.txt" nooutput
blocks = STATS_blocks
set xrange [-40:40]
set yrange [-40:40]
set zrange [-10:10]
set view equal xyz  # Vue 3D équilibrée
set palette rgb 21,22,23  # Définition d'une palette de couleurs
do for [n=0:blocks-1:100]{
    splot "output.txt" index n using 1:2:3 with points pt 7 palette notitle
}

