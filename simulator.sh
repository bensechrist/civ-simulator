#!/bin/bash         
x=100
y=300
mapfile=map
./mapcreate $x $y > $mapfile
./simulation $mapfile $x $y
./printmap
