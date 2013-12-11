all:
	make mapcreate
	make simulation

mapcreate:
	g++ mapcreate.cpp terraincreator.cpp -o mapcreate


clean:
	rm -rf *o mapcreate
	rm -rf *o simulation

simulation:
	g++ simulation.cpp simulate.cpp -o simulation
