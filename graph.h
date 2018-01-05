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
	bool mark; //���ڱ��
	int distance; //���ڼ�¼���·���е����ľ������С�������е����ľ���
	int prior; //���ڼ�¼���·������С�������еĵ�ǰ�ڵ��ǰ��

	int degree; //�ýڵ�Ķ���
	int closeness; //�ýڵ�Ľӽ����Ķ�
	int betweenness; //�ýڵ�Ľ������Ķ�

	int movieID;
	string movieName;
	set<int> userSet;
	GraphNode(): mark(false), distance(0), prior(-1),
		degree(0), closeness(0), betweenness(0)
	{
	}
}; //ÿ���ڵ����Ϣ

class Graph
{
public:
	Graph();
	Graph(int v);
	~Graph();
	void init();
	void extractInfo(string& movieName, string& userName, const string& text);
	void createGraph();
	void addEdge(int begin, int end, int weight); //��ͼ����ӱ�
	void floyd(); //��floyd�㷨��ÿ���������·��
	int shortestPath(int begin, int end); //���begin��end֮������·��
	void centrality(); //��ÿ���ڵ�����Ķ�
	void showCtrlty(ostream& out) const; //���ÿ���ڵ�����Ķ�
	void prim(); //TODO: ��prim�㷨��ͼ����С������
	void showShortestTree(ostream& out) const;
private:
	void initNode()
	{
		for (int i = 0; i < vertex_num; ++i)
		{
			nodes[i].mark = false;
			nodes[i].distance = MAX_DIST;
			nodes[i].prior = -1;
		}
	} //����dijkstra�㷨��prim�㷨�нڵ���Ϣ�ĳ�ʼ��

	int edge_num; //�ߵ�����
	int vertex_num; //�ڵ������
	int **graphMatrix; //ͼ���ڽӾ���
	int **distMatrix; //ͼ����̾������
	int **pathMatrix; //ͼ����̾���·������
	vector<GraphNode> nodes; //����ÿ���ڵ����Ϣ
	map<string, int> movieMap; //��Ӱ����ID��ӳ��
	map<string, int> userMap; //�û�����ID��ӳ��
	string filename;
};

#endif // !GRAPH_H
