#include <iostream>
using namespace std;

typedef char Datatype;
const int Maxsize = 10;

class Queque
{
public:
	Queque() { head = 0; tail = 0; }       //初始化
	bool isempty() { return (head == tail); };
	bool enqueque(Datatype e);
	bool dequeque(Datatype &e);
	Datatype elms[Maxsize];
	int head;
	int tail;
};

bool Queque::enqueque(Datatype e)
{
	if (tail + 1 == head)return false;
	else
	{
		elms[tail] = e;
		if (tail == Maxsize - 1)tail = 0;
		else tail++;
		return true;
	}
}

bool Queque::dequeque(Datatype &e)
{
	if (head == tail)return false;
	else
	{
		e = elms[head];
		if (head == Maxsize - 1)head = 0;
		else head++;
		return true;
	}
}
int main()
{
	Queque q;
	cout << q.isempty() << endl;
	if (!q.enqueque('a'))cout << "上溢" << endl;
	if (!q.enqueque('b'))cout << "上溢" << endl;
	if (!q.enqueque('c'))cout << "上溢" << endl;
	char e;
	if (!q.dequeque(e))cout << "下溢" << endl;
	else cout << e << endl;
	if (!q.enqueque('d'))cout << "上溢" << endl;
	if (!q.enqueque('e'))cout << "上溢" << endl;
	if (!q.enqueque('f'))cout << "上溢" << endl;
	while (!q.isempty())
	{
		q.dequeque(e); cout << e << " ";
	}
	return 0;
}
