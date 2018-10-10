#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class Stack:public vector<T> //公用继承vector类
{
public:
	//empty(),size()函数接口可以直接使用
	void Push(T const&e) { (*this).push_back(e); } //入栈
	T Pop()
	{
		T top = (*this).back();
		(*this).pop_back();
		return top;
	}//出栈，删除最后一个元素返回之
	T GetTop() { return (*this).back(); } //取顶，返回栈顶元素
};

int main()
{
	Stack <char> s; //初始化栈s
	cout << "当前栈状态为：";
	if (s.empty()) { cout << "空" << endl; }
	else cout << "非空" << endl;
	s.Push('a');
	s.Push('b');
	s.Push('c');
	s.Push('d');
	s.Push('e');
	cout << "当前栈状态为：";
	if (s.empty()) { cout << "空" << endl; }
	else cout << "非空" << endl;

	cout << "输出出栈序列：";
	for (int i = s.size(); i > 0; i--)
	{
		cout << s.Pop() << " ";

	}
	cout << endl;
	cout << "当前栈状态为：";
	if (s.empty()) { cout << "空" << endl; }
	else cout << "非空" << endl;
	s.~Stack(); //释放内存
	return 0;

}
