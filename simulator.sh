#!/bin/bash         
x=90
y=40
mapfile=map
./mapcreate $x $y > $mapfile
./simulation $mapfile $x $y
./printmap
