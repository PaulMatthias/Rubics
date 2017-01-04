#!/bin/bash

make -j
./main
cd plots
gnuplot plot_colours.pl
feh colour*
cd ..

