#!/bin/bash         
x=50
y=10
mapfile=map
./mapcreate $x $y > $mapfile
./simulation $mapfile $y $x
./printmap
