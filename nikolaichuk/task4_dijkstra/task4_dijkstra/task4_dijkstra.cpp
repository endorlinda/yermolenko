#include "stdafx.h"
#include <iostream>
#include "Graph.h"


int main()
{
	Graph graph;
	int fromVertex = 0;
	
	graph.loadFromFile("graph.txt");
	
	graph.printGraph();
	std::cout << std::endl;

	std::vector<int> distances = graph.findMinDistances();

	for (int i = 0; i < distances.size(); i++) {
		std::cout << "distance from " << fromVertex << 
			" to " << i << " is " << distances[i] << std::endl;
	}

    return 0;
}

