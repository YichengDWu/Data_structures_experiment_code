#include <iostream>
using namespace std;

typedef char Datatype;
class Node
{
public:
	Datatype key;
	Node* next;
};

class linklist
{
public:
	linklist(); //创建一个单链表
	~linklist(); //销毁单链表
	void creatlist(Datatype a[], int n);//尾插法
	void print();  //输出单链表
	int getlen(); //得到链表的长度
	bool isempty(); //判断是否为空
	Datatype getelm(int i); //按位置查找元素
	int locate(Datatype e); //按值查找元素位置
	bool insert(Datatype elm, int i); //在指定位置插入元素
	bool Delete(int i); //删除指定位置元素

private:
	Node *head;
};

linklist::linklist()  //初始化
{
	head = new Node;
	head->key = NULL;
	head->next = NULL;
}
linklist::~linklist() //删除所有结点
{
	Node *temp;
	head = head->next;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
	cout << "链表内存已释放" << endl;
}

void linklist::creatlist(Datatype a[], int n) 
{
	Node *tail = head;//指向尾结点
	for (int i = 0; i < n; i++)
	{
		Node *temp = new Node;
		temp->key = a[i];
		tail->next = temp;
		tail = temp;
	}
	tail->next = NULL;
}

void linklist::print()
{
	Node *p = head->next;
	cout << "当前链表为：";
	while (p != NULL) { cout << p->key<<' '; p = p->next; }
	cout << endl;
}
int linklist::getlen()
{
	Node *p = head->next;
	int i = 0;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

bool linklist::isempty()
{
	bool flag = true;
	if (head->next != NULL) { flag = false; }
	return flag;
}

Datatype linklist::getelm(int i)
{
	int j = 1;
	Node *p = head->next;
	while (i != j)
	{
		j++;
		p = p->next;
	}
	return p->key;
}
int linklist::locate(Datatype e)
{
	int i = 1;
	Node *p = head->next;
	while (p != NULL && p->key != e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL) { return 0; }//0表示没有找到
	else
		return i;
}

bool linklist::insert(Datatype elm, int i)
{
	if (i <= 0 || i > (*this).getlen()+1) { return false; }
	else
	{
		Node *newelm = new Node; //创建一个新结点
		newelm->key = elm;

		int j = 1;
		Node *p = head->next;
		while (j != i-1)
		{
			j++;
			p = p->next;
		}
		newelm->next = p->next;
		p->next = newelm;
		return true;
	}
}

bool linklist::Delete(int i)
{
	if (i <= 0 || i > (*this).getlen()) { return false; }
	else
	{
		int j = 1;
		Node *p = head->next;
		while (j != i - 1)
		{
			j++;
			p = p->next;
		}
		Node *temp = p->next;
		p->next = temp->next;
		delete temp;
		return true;
	}

}

int main()
{
	linklist h;
	Datatype a[5] = { 'a','b','c','d','e' };
	int n = 5;
	h.creatlist(a, 5);
	h.print();
	cout << "当前链表长度为：" << h.getlen() << endl;
	if (h.isempty()) { cout << "当前链表状态：空" << endl; }
	else { cout << "当前链表状态：非空" << endl; }
	cout << "h第三个元素为：" << h.getelm(3) << endl;
	cout << "a的位置为：" << h.locate('a') << endl;
	h.insert('f', 4);
	h.print();
	h.Delete(3);
	h.print();
	return 0;
}