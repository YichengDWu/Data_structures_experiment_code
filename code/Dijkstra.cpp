#include<iostream>
#include<deque>
using namespace std;

#define MAX 7
#define INF 1000000

void Dijkstra(int A[][MAX], int v)
{
	void disp(int A[][MAX], int dist[], int path[], int S[], int v);//声明
	//dist[j]表示源点到vj的距离;
	//path[j]表示源点到vj的最短路径的vj的前驱结点的编号
	//S[MAX]存放被访问的结点,S[i] = 1表示被访问
	int dist[MAX], path[MAX], S[MAX];
	int i, j, u;
	for (i = 0; i < MAX; i++)
	{
		dist[i] = A[v][i];
		S[i] = 0;
		if (dist[i] < INF) path[i] = v;
		else path[i] = -1;
	}
	S[v] = 1;  //源点防止S中
	for (i = 0; i < MAX-1; i++)
	{
		int mindis = INF;
		for(j = 0;j<MAX;j++)  
			if (S[j] == 0 && dist[j] < mindis)
			{
				u = j;
				mindis = dist[j];
			}
		S[u] = 1;  //最小距离的顶点放入S
		for (j = 0; j < MAX; j++) //调整路径
		{
			if (S[j] == 0)
				if(A[u][j]<INF)
					if (dist[u] + A[u][j] < dist[j])
					{
						dist[j] = dist[u] + A[u][j];
						path[j] = u;
					}
		}
	}
	disp(A, dist, path, S, v);
}

void disp(int A[][MAX], int dist[], int path[], int S[], int v)
{
	deque <int> repath;
	for(int i = 0;i<MAX;i++)
		if (S[i] == 1 && i != v)
		{
			if (dist[i] == INF)cout << "从源点v" << v << "到顶点v" << i << "无路径";
			else
			{
				cout << "从源点v" << v << "到顶点v" << i << "的最短路径长为：" << dist[i] << endl;
				cout << "最短路径为：v"<<v;
				int p = i;
				while (p != v)
				{
					repath.push_front(p);
					p = path[p];
				}
				while (repath.empty() != true)
				{
					cout << "->v" << repath[0];
					repath.pop_front();
				}
			}
			cout << endl;
		}
}

int main()
{
	int A[][MAX] = { 0, 4, 6, 6, INF, INF, INF,
				   INF, 0, 1, INF, 7, INF, INF,
				   INF,INF,0, INF, 6, 4,   INF,
				   INF,INF,2, 0, INF, 5,   INF,
				   INF,INF,INF,INF, 0, INF,  6,
				   INF,INF,INF,INF, 1, 0  ,  8,
				   INF,INF,INF,INF,INF,INF,  0 };
	Dijkstra(A, 0);
	return 0;
}
