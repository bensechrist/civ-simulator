all:
	make mapcreate printmap simulation plane

mapcreate:
	g++ mapcreate.cpp terraincreator.cpp -o mapcreate

printmap:
	g++ printmap.cpp -o printmap -lncurses

simulation:
	g++ simulation.cpp simulate.cpp -o simulation

plane:
	g++ plane.cpp -o plane

clean:
	rm -rf mapcreate simulation printmap plane action_list.txt map *.o
