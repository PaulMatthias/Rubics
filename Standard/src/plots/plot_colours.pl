reset
set terminal png 
tmax=16
set xtics -0.5,1,1.5 format ""
set ytics -0.5,1,1.5 format ""

do for [t=0:tmax]{
  set grid front xtics ytics lw 1.5 lt -1 lc rgb 'black'
  #unset tics
  set output "colour_step".t.".png"
  set xrange [-0.5:2.5]
  set yrange [2.5:-0.5]
  set size ratio -1

  set palette model RGB defined(0 "red", 1 "blue", 2 "yellow", 3 "orange", 4 "grey", 5 "green")

  set multiplot layout 3,2 

  set cbrange [0:5]
  #unset border
  unset colorbox
  set key above 

  plot '../data/colour_side0_step'.t.'.txt' matrix with image title 'Front' 
  plot '../data/colour_side1_step'.t.'.txt' matrix with image title 'Unterseite' 
  plot '../data/colour_side2_step'.t.'.txt' matrix with image title 'Rückseite' 
  plot '../data/colour_side3_step'.t.'.txt' matrix with image title 'Oberseite' 
  plot '../data/colour_side4_step'.t.'.txt' matrix with image title 'Links' 
  plot '../data/colour_side5_step'.t.'.txt' matrix with image title 'Rechts' 

  unset multiplot
}
