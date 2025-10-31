set output "QKD_Total_Graph.png"
set title "QKD Total Graph"
set xlabel "Time (seconds)"
set ylabel "Key material (bits)"

set autoscale y
set border linewidth 2
set terminal pngcair size 1524,768 enhanced font 'Helvetica,18'
set style line 1 linecolor rgb 'red' linetype 1 linewidth 1
set style line 4 linecolor rgb "#8A2BE2" linetype 1 linewidth 1
set style line 7 linecolor rgb 'gray' linetype 0 linewidth 1
set style line 8 linecolor rgb 'gray' linetype 0 linewidth 1 
set grid ytics lt 0 lw 1 lc rgb "#ccc"
set grid xtics lt 0 lw 1 lc rgb "#ccc"
set mxtics 5
set grid mxtics xtics ls 7, ls 8
set arrow from graph 1,0 to graph 1.03,0 size screen 0.025,15,60 filled ls 3
set arrow from graph 0,1 to graph 0,1.03 size screen 0.025,15,60 filled ls 3
set style fill transparent solid 0.4 noborder
set key outside
set key right bottom
plot "QKD_Total_Graph_data.dat" index 0 title "Amount of key material" with linespoints  ls 1, "QKD_Total_Graph_data.dat" index 1 title "Threshold" with linespoints  ls 4
