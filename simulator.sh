#!/bin/bash         
x=50
y=50
mapfile=map
./mapcreate $x $y > $mapfile
./simulation map $x $y
