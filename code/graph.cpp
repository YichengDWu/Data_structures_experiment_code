#include <iostream>
using namespace std;

#define MAX 5
#define INF 1000000
typedef char InfoType;

class Enode  //边结点
{
public:
	int loc; //该点的编号
	int weight; //边的权值
	Enode *next_v;
	Enode() { next_v = NULL; }
};

class Vnode    //头结点
{
public:
	InfoType info;
	Enode *first_v; //第一个相邻的边结点
};

class Graph
{
public:
	int n; //节点数
	int m; //边数
	Vnode head[MAX];
	void create(int A[][MAX], int num, int edges); //根据邻接矩阵创建邻接表
	Graph();
	void release();
	void toMat(int B[][MAX]);
};

Graph::Graph()
{
	for (int i = 0; i < MAX; i++)
	{
		head[i].first_v = NULL;
	}
}

void Graph::create(int A[][MAX],int num, int edges)
{
	n = num;
	m = edges;
	int i,j;
	for (i = 0; i < num; i++)
		for(j = 0;j <num; j++)
		{
			if (A[i][j] != 0 && A[i][j] != INF)
			{
				Enode *p = new Enode;
				p->loc = j;
				p->weight = A[i][j];
				p->next_v = head[i].first_v; //头插法
				head[i].first_v = p;
			}
		}
}
void Graph::release()
{
	int i; Enode *temp, *p;
	for (i = 0; i < n; i++)
	{
		p = head[i].first_v;
		while (p != NULL)
		{
			temp = p;
			p = p->next_v;
			delete temp;
		}
		
	}
}

void Graph::toMat(int B[][MAX])
{
	int i; 
	Enode *p = head[0].first_v;
	for (i = 0; i < MAX; i++)
	{
		p = head[i].first_v;
		while (p != NULL)
		{
			B[i][p->loc] = p->weight;
			p = p->next_v;
		}
	}

}


int main()
{
	int ADJ[MAX][MAX] = { 0, 8, INF, 5, INF,
						INF, 0, 3, INF, INF,
						INF, INF, 0, INF, 6,
						INF, INF, 9, 0, INF,
						1, 5, 8, 5, 0 };
	int BDJ[MAX][MAX] = { 0, INF, INF, INF, INF,
						INF, 0, INF, INF, INF,
						INF, INF, 0, INF, INF,
						INF, INF, INF, 0, INF,
						INF, INF, INF, INF, 0 };

	Graph g;
	g.create(ADJ, 5, 10);
	g.toMat(BDJ);
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		{
			if (BDJ[i][j] == INF)
			{
				cout << "INF"<<'\t';
			}
			else cout << BDJ[i][j] << '\t';
			if (j == MAX-1)cout << '\n';
		}
	g.release();
	return 0;
}
