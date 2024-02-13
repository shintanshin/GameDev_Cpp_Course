#include <iostream>
#include "Graph.h"

//#define TIME_LOG_ENABLED
int getTime() { return 1; }

int main()
{
	GraphAdjList graph(10);

	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(0, 3);

	graph.addEdge(1, 4);
	graph.addEdge(2, 5);
	graph.addEdge(2, 6);
	graph.addEdge(3, 7);

	graph.addEdge(4, 8);
	graph.addEdge(5, 9);


#ifdef TIME_LOG_ENABLED
	int startTime = getTime();
#endif

	graph.BFS();

#ifdef TIME_LOG_ENABLED
	int endTime = getTime();
	int diff = endTime - startTime;
	std::cout << "Time used for BFS: " << diff << std::endl;
#endif

	int level = 3;
	int numberOfNodes = graph.numberOfNodesInLevel(level);
	std::cout << "Number of nodes at level " << level << ": " << numberOfNodes << std::endl;

	if (graph.isStronglyConnected())
	{
		std::cout << "The graph is strongly connected." << std::endl;
	}
	else
	{
		std::cout << "The graph isn't strongly connected." << std::endl;
	}

}