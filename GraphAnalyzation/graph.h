#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <string>	
#include <iostream>
#include <map>
#include <set>
using namespace std;

const int MAX_DIST = (int)1e8;

struct GraphNode
{
	bool mark; //用于标记
	int distance; //用于记录最短路径中到起点的距离或最小生成树中到树的距离
	int prior; //用于记录最短路径或最小生成树中的当前节点的前继

	int degree; //该节点的度数
	int closeness; //该节点的接近中心度
	int betweenness; //该节点的介数中心度

	int movieID;
	string movieName;
	set<int> userSet;
	GraphNode(): mark(false), distance(0), prior(-1),
		degree(0), closeness(0), betweenness(0)
	{
	}
}; //每个节点的信息

class Graph
{
public:
	Graph();
	Graph(int v);
	~Graph();
	void init();
	void extractInfo(string& movieName, string& userName, const string& text);
	void createGraph();
	void addEdge(int begin, int end, int weight); //向图中添加边
	void floyd(); //用floyd算法求每两点间的最短路径
	int shortestPath(int begin, int end); //求从begin到end之间的最短路径
	void centrality(); //求每个节点的中心度
	void showCtrlty(ostream& out) const; //输出每个节点的中心度
	void prim(); //TODO: 用prim算法求图的最小生成树

private:
	void initNode()
	{
		for (int i = 0; i < vertex_num; ++i)
		{
			nodes[i].mark = false;
			nodes[i].distance = MAX_DIST;
			nodes[i].prior = -1;
		}
	} //用于dijkstra算法和prim算法中节点信息的初始化

	int edge_num; //边的数量
	int vertex_num; //节点的数量
	int **graphMatrix; //图的邻接矩阵
	int **distMatrix; //图的最短距离矩阵
	int **pathMatrix; //图的最短距离路径矩阵
	vector<GraphNode> nodes; //储存每个节点的信息
	map<string, int> movieMap; //电影名与ID的映射
	map<string, int> userMap; //用户名与ID的映射
	string filename;
};

#endif // !GRAPH_H
