set title "b) N=10"
set xlabel "x"
set ylabel "u(x)"
set xrange [0:1.1]
set yrange [0:1.5]
plot "data1.dat" u 1:2 title "u_calculated", "data2.dat" u 1:2 title "u_closed_form"

set term png
set output "result_b_1.png"
replot
set term x11
