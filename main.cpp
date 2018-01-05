#include <iostream>
#include <fstream>
#include "graph.h"
using namespace std;

#define TEST2

int main()
{
#ifdef TEST1
	int v, e;
	cin >> v >> e ;
	Graph graph(v);
	int Rs, Re, w;
	for (int i = 0; i < e; ++i)
	{
		cin >> Rs >> Re >> w;
		graph.addEdge(Rs, Re, w);
		graph.addEdge(Re, Rs, w);
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
	graph.prim();
	ofstream out("out.csv", ios::out);
	graph.showCtrlty(out);
	graph.showShortestTree(out);
#endif // TEST

#ifdef TEST2
	Graph graph;
	graph.floyd();
	graph.centrality();
	graph.prim();
	ofstream fout("out.csv", ios::out);
	graph.showCtrlty(fout);
	fout.close();
	fout.open("tree.csv",ios::out);
	graph.showShortestTree(fout);
#endif // TEST2

	return 0;
}