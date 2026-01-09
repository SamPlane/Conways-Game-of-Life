# Conways-Game-of-Life

This repository hosts my implementation of Conway's game of life (details of which can be found at https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) to demonstrate the use of parallel programming frameworks. 

I have written a serial implementation using programming techniques that optimise for speed (these are highlighted in the file main.c) and different parallel frameworks are implemented in branches that derive from this main serial branch.

To compare implementations, a standard benchmark of 100x100 cells run for 1 million generations will be used with random number generator seed of 2245. This is run on a computer with an i3-9100f and 16GB of DDR4 RAM.

All other applications are closed during this benchmark.

Serial - 141.517 seconds
