#!/bin/bash         
x=50
y=20
mapfile=map
./mapcreate $x $y > $mapfile
./simulation $mapfile $x $y
./printmap
