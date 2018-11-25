#include <iostream>
#include<deque>
using namespace std;

#define M 6
#define N 6

class Enode  //边结点
{
public:
	int I,J; //该点的编号
	Enode *pre;  //路径上的前一个结点 
	Enode *next_v;
	Enode(int i, int j) 
	{
		I = i; J = j; next_v = NULL;
	}
	
};

class Vnode    //头结点
{
public:
	Enode *first_v; //第一个相邻的边结点
};

class Graph
{
public:
	Vnode head[M][N]; //头结点的位置
	Graph(int[][N]);
	void find_path(int, int, int, int);
	//void release();

	
};

Graph::Graph(int A[M][N])
{
	for (int i = 1; i < M-1; i++)
		for(int j = 1;j<N-1;j++)
		{
			if (A[i][j] == 0)  //只创建走得通的  
			{
				head[i][j].first_v = NULL;
				if (A[i - 1][j] == 0)
				{
					Enode *p = new Enode(i-1, j);
					p->next_v = head[i][j].first_v;
					head[i][j].first_v = p;
				}
				if (A[i + 1][j] == 0)
				{
					Enode *p = new Enode(i+1, j);
					p->next_v = head[i][j].first_v;
					head[i][j].first_v = p;
				}
				if (A[i][j-1] == 0)
				{
					Enode *p = new Enode(i, j-1);
					p->next_v = head[i][j].first_v;
					head[i][j].first_v = p;
				}
				if (A[i][j + 1] == 0)
				{
					Enode *p = new Enode(i, j + 1);
					p->next_v = head[i][j].first_v;
					head[i][j].first_v = p;
				}
			}
			else head[i][j].first_v = NULL;
		}
}



void Graph::find_path(int v1i, int v1j, int v2i, int v2j)
{
	deque<Enode *> s;
	int visited[M][N];
	int i, j;
	for (i = 0; i < M; i++)
		for(j = 0; j< N;j++)
		{
			visited[i][j] = 0;
		}
	Enode *now = new Enode(v1i, v1j); //创建源点 
	visited[v1i][v1j] = 1;  //访问源点
	s.push_back(now); //源点进队
	bool flag = false; //默认没有找到路径
	while (flag!=true)
	{	
		now = s[0]; //更新Now指向当前处理的结点
		int w[2] = { s[0]->I, s[0]->J };
		s.pop_front();//出队
		Enode *p = head[w[0]][w[1]].first_v; //处理该结点的邻接结点
		while (p != NULL)
		{
			if (p->I == v2i && p->J == v2j)
			{
				deque<int> path;
				path.push_front(w[1]); path.push_front(w[0]);
				while(w[0] != v1i || w[1]!= v1j)
				{
					now = now->pre;
					w[0] = now->I; w[1] = now->J;
					path.push_front(w[1]); path.push_front(w[0]);
				}
				while (path.empty() == false)
				{
					cout << "("<<path[0] << "," << path[1] << ")" << endl;
					path.pop_front(); path.pop_front();
				}
				cout << "(" << v2i << "," << v2j << ")" << endl;
				flag = true; break;
			}

			
			else if (visited[p->I][p->J] == 0)
			{
				
				p->pre = now;  //记录下路径上前一个元素
				visited[p->I][p->J] = 1;
				s.push_back(p);
			}
			p = p->next_v;
		}
	}
}



int main()
{
	int maze[M][N] = { 1, 1, 1, 1, 1, 1,
					  1, 0, 0, 0, 1, 1,
					  1, 0, 1, 0, 0, 1,
					  1, 0, 0, 0, 1, 1,
					  1, 1, 0, 0, 0, 1,
					  1, 1, 1, 1, 1, 1 };
	Graph g(maze);
	g.find_path(1,1,4,4);
	return 0;
}
