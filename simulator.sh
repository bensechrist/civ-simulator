#!/bin/bash         
x=40
y=90
mapfile=map
./mapcreate $x $y > $mapfile
./simulation $mapfile $x $y
./printmap
