all:
	make mapcreate
	make simulation
	make printmap

mapcreate:
	g++ mapcreate.cpp terraincreator.cpp -o mapcreate

printmap:
	g++ printmap.cpp -o printmap -lncurses


clean:
	rm -rf *o mapcreate
	rm -rf *o simulation
	rm -rf *o printmap

simulation:
	g++ simulation.cpp simulate.cpp -o simulation
