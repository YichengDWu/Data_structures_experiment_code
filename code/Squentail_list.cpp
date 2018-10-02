#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Sqlist :public vector<T>
{
public:
	//size,empty,clear,erase等接口可以直接用
	void creat(T a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			(*this).push_back(a[i]);
		}
	}
	void print()
	{
		for (int i = 0; i < (*this).size(); i++)cout << (*this)[i] << ' ';
		cout << endl;
	}
	int locelm(T elm)
	{
		int i = 0;
		while ((*this)[i] != elm)
		{
			i++;
		}
		return i;
	}
	
};

int main()
{
	char a[5] = { 'a','b','c','d','e' };
	Sqlist <char> L;
	L.creat(a, 5);
	L.print();
	cout << "顺序表长度为: " << L.size() << endl;
	if (L.empty())cout << "当前状态为：空" << endl;
	else cout<< "当前状态为：非空" << endl;
	cout << "第三个元素为:" << L[2] << endl;
	cout << "a元素的位置为：" << L.locelm('a') << endl;
	L.insert(L.begin()+3,'f');
	cout << "现在链表为："; L.print();cout << endl;
	L.erase(L.begin()+2);
	cout << "现在链表为："; L.print(); cout << endl;
	L.clear();
	return 0;
}