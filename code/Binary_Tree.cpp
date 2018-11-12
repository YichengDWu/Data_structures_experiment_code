#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef char Datatype;

class BTnode
{
public:
	Datatype key;
	BTnode *lchild;
	BTnode *rchild;
	BTnode(Datatype &k) { key = k; lchild = NULL; rchild = NULL; }
};

class BTree
{
public:
	BTnode *root;
	BTree() { root = NULL; }
	friend istream& operator>>(istream &, BTree &);    //创建二叉树
	void print(BTnode *);
	friend ostream& operator<<(ostream &, BTree &);    //输出二叉树
	void release(BTnode *b);	 //销毁二叉树
	~BTree() { release(root); }
	BTnode *search(BTnode *, Datatype x);

};

istream& operator>>(istream &in, BTree &bt)
{
	vector<BTnode *>st;
	BTnode *p;
	string s;
	in >> s;
	int i = 0, k = 0; //k表示要处理的是左孩子或右孩子
	while (s[i] != '\0')
	{
		switch (s[i])
		{
		case '(': st.push_back(p); k = 1; break; //开始处理左孩子
		case ')': st.pop_back(); break;
		case ',': k = 2; break;
		default:
			p = new BTnode(s[i]);
			if (bt.root == NULL) { bt.root = p; } 
			else
			{
				if (k == 1) st.back()->lchild = p;
				else st.back()->rchild = p;
			}
			
			break;
		}
		i++;
	}
	return in;
}

void BTree::print(BTnode *p)
{
	if (p != NULL)
	{
		cout << p->key;
		if (p->lchild != NULL || p->rchild != NULL)
		{
			cout << "(";
			print(p->lchild);
			if (p->rchild != NULL) cout << ",";
			print(p->rchild);
			cout<<")";
		}
	}
}

ostream& operator<<(ostream &out, BTree &bt)
{
	bt.print(bt.root);
	out<<endl;
	return out;
}

void BTree::release(BTnode *b)
{
	if (b != NULL)
	{
		release(b->lchild);
		release(b->rchild);
		delete b;
	}
}

BTnode* BTree::search(BTnode *b, Datatype x)
{
	BTnode* temp;
	if (b == NULL)return NULL;
	else if (b->key == x) return b;
	else
	{
		temp = search(b->lchild, x);
		if (temp != NULL)
			return temp;
		else return search(b->rchild, x);
	}
}



int main()
{
	BTree b;
	cin >> b;
	cout << b;
	//cout<<(b.search(b.root, 'C'))->key;
	return 0;
}
