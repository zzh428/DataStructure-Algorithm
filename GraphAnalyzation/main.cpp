#include <iostream>
#include <fstream>
#include "graph.h"
using namespace std;

#define TEST

int main()
{
#ifdef TEST
	int v, e, Ts, Te;
	cin >> v >> e >> Ts >> Te;
	Graph graph(v);
	int Rs, Re, w;
	for (int i = 0; i < e; ++i)
	{
		cin >> Rs >> Re >> w;
		graph.addEdge(Rs - 1, Re - 1, w);
		graph.addEdge(Re - 1, Rs - 1, w);
	}
	for (int i = 0; i < v; ++i)
	{
		for (int j = 0; j < v; ++j)
		{
			cout << i << " -> " << j << ":\t\t";
			graph.shortestPath(i, j);
		}
	}
	graph.centrality();
	ofstream out("out.csv", ios::out);
	graph.showCtrlty(out);
#endif // TEST
	return 0;
}