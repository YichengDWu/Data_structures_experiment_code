#include<iostream>
#include<vector>
using namespace std;

class HTnode
{
public:
	HTnode() 
	{
		parent = -1;
		lchild = -1;
		rchild = -1;
	}
	char data; //存放字符
	double weight; //权重
	int parent; //双亲结点的位置
	int lchild; 
	int rchild;
	HTnode(char d, double w):data(d), weight(w)
	{
		parent = -1;
		lchild = -1;
		rchild = -1;
	};
};

void creat(HTnode h[], int n)
{
	for (int i = n; i < n * 2 - 1; i++)
	{
		double min1 = 1.1, min2 = 1.1;
		int lnode = -1, rnode = -1;
		for (int k = 0; k < i; k++)
		{
			if(h[k].parent == -1)
				if (h[k].weight < min1)
				{
					min2 = min1; rnode = lnode;
					min1 = h[k].weight; lnode = k;
				}
				else if (h[k].weight < min2)
				{
					min2 = h[k].weight; rnode = k;
				}
		}
		h[i].weight = h[lnode].weight + h[rnode].weight;
		h[i].lchild = lnode; h[i].rchild = rnode;
		h[lnode].parent = i; h[rnode].parent = i;
	}
}

void HTcode(HTnode h[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << h[i].data << ": ";
		vector <int> htcode;
		int temp = i;
		while (h[temp].parent != -1)
		{
			int par = h[temp].parent;
			if (h[par].lchild == temp) { htcode.insert(htcode.begin(), 0); }
			else if(h[par].rchild == temp) { htcode.insert(htcode.begin(), 1); }
			temp = par;
		}
		int k = 0;
		while (k < htcode.size())
		{
			cout << htcode[k++];
		}
		cout << endl;
	}
}
int main()
{
	HTnode ht[8*2-1];
	ht[0] = HTnode('a', 0.07);
	ht[1] = HTnode('b', 0.19);
	ht[2] = HTnode('c', 0.02);
	ht[3] = HTnode('d', 0.06);
	ht[4] = HTnode('e', 0.32);
	ht[5] = HTnode('f', 0.03);
	ht[6] = HTnode('g', 0.21);
	ht[7] = HTnode('h', 0.10);
	creat(ht, 8); //创建哈夫曼树
	HTcode(ht, 8);
	return 0;
	

}
