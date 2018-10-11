#include <iostream>
using namespace std;

typedef char Datatype;

class Node
{
public:
    Datatype key;
    Node * next;
};

class L_Stack
{
public:
    L_Stack(); //创建一个链栈栈
	~L_Stack(); //销毁链栈
	bool isempty(); //判断是否为空
	void Push(Datatype const& ); //入栈
	bool Pop(Datatype &); //出栈，将栈顶元素放到e里
private:
    Node *head;
};

L_Stack::L_Stack()
{   
    head = new Node;
    head->key = NULL;
    head->next = NULL;
}
L_Stack::~L_Stack()
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

bool L_Stack::isempty()
{
    if(head->next == NULL)return true;
    else return false;
}

void L_Stack::Push(Datatype const& e)
{
	Node *a = new Node;
	a->key = e;
	a->next = head->next;
	head->next = a;
}
bool L_Stack::Pop(Datatype &e)
{
	if(head->next == NULL) return false;
	else
	{
		e = head->next->key;
		Node *temp = head->next;
		head->next = head->next->next;
		delete temp;
		return true;
	}
}



int main() 
{
	L_stack s;
	return 0;
}
