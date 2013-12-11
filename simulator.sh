#!/bin/bash         
x=80
y=60
mapfile=map
./mapcreate $x $y > $mapfile
./simulation $mapfile $x $y
./printmap
