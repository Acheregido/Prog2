set title "Trabajo curso 20-21"
set xlabel "n"
set ylabel "T_{exec}(microsegundos)"
set grid
unset key #esconde leyenda con nombre del fichero de datos

set term qt 0
plot "tnumifb.txt" with lines

set term qt 1
plot "tnumidv.txt" with lines

pause -1
