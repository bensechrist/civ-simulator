// James Tobat - simulation.cpp
// Client code for simulation class

#include "simulate.h"
using namespace std;

int main(int argc, char* argv[])
{
	unsigned int x,y;
	ifstream input;
	
	// Ensures that there are enough arguments in the command line
	if(argc < 3)
	{
		cerr<<"simulation: Not enough arguments, simulation  failed!\n";
	}
	else
	{
		input.open(argv[1]);
		x = atoi(argv[2]);
		y = atoi(argv[3]);
	}

	// Begins a new simulation if the correct paramters were recieved
	simulate X(x,y);

	// Simulation is over if the map file can't load, otherwise, the map is built
	// in simulation.
	if(!input.is_open())
	{
		cerr<<"simulation: Could not open map file, simulation failed!\n";
	}
	else
	{
		X.populateMap(input);
	}

	// Parses the config file in order to set some class variables for simulation.
	ifstream conf("config");

	// Simulation is over if the config file cannot be opened. 
	// If it is, then the config file is parsed and the simulation is ran.
	if(!input.is_open())
	{
		cerr<<"simulation: Could not open configuration file, simulation failed!\n";
	}
	else
	{
		X.parseConfig(conf);
		X.runSim();
	}
	return 0;
}

