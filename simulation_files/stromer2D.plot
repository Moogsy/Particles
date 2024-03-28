#! /usr/bin gnuplot
set terminal gif animate delay 10
set output "stromer.gif"
stats "output.txt" nooutput
blocks = STATS_blocks
set xrange[-40:40]
set yrange[-10:10]
do for [n=0:blocks-1:100]{
    plot "output.txt" i n with points notitle pt 7 
}
