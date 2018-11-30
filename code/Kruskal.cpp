#include<iostream>
using namespace std;

#define n 7
#define m 9
#define INF 10000000

class Edge
{
public:
	int u;
	int v;
	int w;
	friend void merge(Edge *, int, int, int);

};
void merge(Edge *a, int start, int mid, int end)
{
	int len = end - start +1;
	Edge *temp = new Edge[len];
	int i = start, j = mid + 1;
	int k = 0;
	while (i <= mid && j <= end)
	{
		if (a[i].w <= a[j].w)temp[k++] = a[i++];
		else { temp[k++] = a[j++]; }
	}
	while (i <= mid)
	{
		temp[k++] = a[i++];
	}
	while (j <= end)
	{
		temp[k++] = a[j++];
	}
	for (int t = 0; t < len; t++)
	{
		a[t + start] = temp[t];
	}
	delete[]temp;
}

void mergesort(Edge a[], int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergesort(a, start, mid); //二分法递归左边
		mergesort(a, mid + 1, end);
		merge(a, start, mid, end);
	}
}


void Kruskal(int A[][n])
{
	int flag[n]; //flag[i] = j表示vi所在连通分支编号为j
	Edge E[m];  //存放所有边
	int i, j, k=0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
			if (A[i][j] != 0 && A[i][j] != INF)
			{
				E[k].u = i; E[k].v = j; E[k].w = A[i][j];
				k++;
			}
		flag[i] = i;
	}	
	mergesort(E, 0, m - 1);
	k = 1; //k表示当前处理第一条边；
	j = 0;
	while (k < n)   //m' = n-1
	{
		int flag1 = flag[E[j].u];
		int flag2 = flag[E[j].v];
		if (flag1 != flag2)
		{
			cout << "(v" << E[j].u << ", v" << E[j].v << ")" << endl;
			k++;
			for (i = 0; i < n; i++)
			{
				if (flag[i] == flag2)flag[i] = flag1; //统一编号
			}
		}
		j++;

	}
		
}

int main()
{
	int A[n][n] = { 0, 9, INF, INF, INF, 1, INF,
					9, 0, 4,  INF, INF, INF, 3,
				   INF,4, 0,    2, INF, INF,INF,
				   INF, INF,2,  0, 6, INF, 5,
				   INF, INF, INF, 6, 0, 8, 7,
				   1,   INF,INF,INF, 8, 0,INF,
				   INF, 3, INF, 5, 7, INF, 0 };
	Kruskal(A);
	return 0;
}


