#include<iostream>
using namespace std;

template<typename type>
class BSTree
{
public:
	class BSTnode
	{public:
		BSTnode *l;
		BSTnode *r;
		BSTnode *par; //双亲节点
		type key;
		BSTnode() :l(NULL), r(NULL), par(NULL){}
		BSTnode(type data) : l(NULL), r(NULL), par(NULL), key(data){}
	};
	BSTnode *root;
	BSTree() :root(NULL){}
	void create(type[], int);  //创建二叉搜索树
	bool search(const type&)const; //查找
	void LDR(BSTnode *)const; //中序遍历输出
	void remove(BSTnode *); //删除节点
	void transplant(BSTnode *, BSTnode *); //将一颗树替换另外一颗树
	void insert(type v); //插入v
};

template<typename type>
bool BSTree<type>::search(const type& x)const
{
	BSTnode *locPtr = root;
	bool found = false;
	while (!found && locPtr != NULL)
	{
		if (a_data < locPtr->data)
		{
			locPtr = locPtr->left;
		}
		else if (locPtr->data < a_data)
		{
			locPtr = locPtr->right;
		}
		else
		{
			found = true;
		}
	}
	return found;
	return p;
}

template<typename type>
void BSTree<type>::LDR(BSTnode *p)const
{
	if (p != NULL)
	{
		LDR(p->l); cout << p->key<<" ";
		LDR(p->r);
	}
}

template<typename type>
void BSTree<type>::transplant(BSTnode *u, BSTnode *v)
{
	if (u->par == NULL)         //如果u是根节点
	{
		root = v;
	}
	else if (u == u.par.l)    //如果u是做孩子
	{
		u.par.l = v;
	}
	else u.par.r = v;
	if (v != NULL) v.par = u.par;             
}


template<typename type>
void BSTree<type>::remove(BSTnode * x)
{
	if (x == NULL)return;
	else if (x->l == NULL)transplant(x, x->r);
	else if (x->r == NULL)transplant(x, x->l);
	else
	{
		BSTnode *y = x->r, *temp = y;
		while (temp != NULL)
		{
			y = temp;
			temp = temp->l;
		} //y为x的中序后继
		if (y.par != x)
		{
			transplant(y,y->right)
			y->r = x->r;
			y->r->par = y;
		}
		transplant(x, y);
		y->l = x->l;
		y->l->par = y;
	}
}

template<typename type>
void BSTree<type>::insert(type v)
{
	BSTnode *temp = root, *temp2 = NULL;
	BSTnode *V = new BSTnode(v);
	if (root == NULL) root = V;
	else
	{
		while (temp != NULL)
		{
			temp2 = temp;
			if (temp->key > v)temp = temp->l;
			else temp = temp->r;
		}
		V->par = temp2;
		if (v < temp2->key)temp2->l = V;
		else temp2->r = V;

	}

}

template<typename type>
void BSTree<type>::create(type a[], int n)
{
	for (int i = 0; i < n; i++)insert(a[i]);
}

int main()
{
	int a[9] = { 5, 4, 8, 7, 3, 2, 1, 58, 32 };
	BSTree<int> t;
	t.create(a, 9);
	t.LDR(t.root); cout << endl;
	t.insert(15);
	
	t.LDR(t.root);
	return 0;

}
