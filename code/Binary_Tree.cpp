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
	int height(BTnode *);
	int count(BTnode *); //统计有多少个结点
	int level(BTnode *, Datatype); //返回结点x的层次，根结点为第一层

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
			cout << ")";
		}
	}
}

ostream& operator<<(ostream &out, BTree &bt)
{
	bt.print(bt.root);
	out << endl;
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

int BTree::height(BTnode *b)
{
	if (b == NULL)return 0;
	else
	{
		int lheight, rheight;
		lheight = height(b->lchild);
		rheight = height(b->rchild);
		return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
	}
}

int BTree::count(BTnode *b)
{
	if (b == NULL)return 0;
	else return count(b->lchild) + count(b->rchild) + 1;
}


int BTree::level(BTnode *b, Datatype x)
{
	if ( b == NULL )return 0;
	else if (b->key == x)return 1;
	else
	{
		int l;
		l = level(b->lchild, x);
		if (l != 0) return l + 1;  //如果左边找到了
		else
		{
			l = level(b->rchild, x); 
			if (l != 0) return l + 1;  //如果右边找到了
			else return 0; //两边都没找到
		}
		
	}
}


int main()
{
	BTree b;
	cin >> b;
	cout << b;
	cout << "树的高度为：" << b.height(b.root) << endl;
	cout << "树的结点数为：" << b.count(b.root) << endl;
	char n;
	cout << "请输入要查找的结点：";
	cin >> n;
	cout << "结点" << n << "所在的层次为：" << b.level(b.root, n) << endl;
	return 0;
}
