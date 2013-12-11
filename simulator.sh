#!/bin/bash         
x=60
y=50
mapfile=map
./mapcreate $x $y > $mapfile
./simulation $mapfile $x $y
./printmap
