#!/bin/bash         
x=100
y=50
mapfile=map
./mapcreate $x $y > $mapfile
./simulation $mapfile $y $x
./printmap
