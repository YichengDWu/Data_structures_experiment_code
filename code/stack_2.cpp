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



int main() 
{
	return 0;
}
