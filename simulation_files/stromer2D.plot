#! /usr/bin gnuplot
set terminal gif animate delay 5
set output "stromer.gif"
stats "output.txt" nooutput
blocks = STATS_blocks
set xrange[-40:40]
set yrange[-40:40]
do for [n=0:blocks-1:100]{
    plot "output.txt" i n with points notitle pt 7 
}
