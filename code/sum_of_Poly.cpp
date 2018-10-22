#include <iostream>
using namespace std;

class Term  //定义顶多项式多的项
{
public:
	double coef;  //系数
	int power;   //次数
	Term *next;
	Term(double c, int p) : coef(c), power(p) { next = NULL; }
	Term(double c, int p, Term * n) : coef(c), power(p), next(n) {}
	Term *insert(double c, int p)
	{
		next = new Term(c, p);
		return next;
	}
	friend ostream& operator<<(ostream&, const Term &);
};

ostream& operator<<(ostream & out,const Term& t)
{
	if (t.coef == 0) { return out; }
	switch (t.power)
	{
		case 0:out << t.coef; break;
		case 1:
		{
			if (t.coef != 1 && t.coef != -1)cout << t.coef;
			else if (t.coef == -1) out << "-";
			out << "x"; break;
		}
		default:
		{
			if (t.coef != 1 && t.coef != -1)cout << t.coef;
			else if (t.coef == -1) out << "-";
			out << "x^" << t.power; break;
		}
	}
	return out;
}

class Poly
{
private:
	Term *head;
public:
	Poly() { head = new Term(0, -1); }
	~Poly();
	friend ostream& operator<<(ostream &, const Poly&);
	friend istream& operator>>(istream&, Poly&);
	Poly operator+(Poly &);
};

istream& operator>> (istream& in, Poly& poly)
{
	Term *temp = poly.head ;
	double c; int p;
	while (true)
	{
		cout << "请一项一项的升次输入多项式(系数，指数),以输入指数为负数终止:" << endl;
		in >> c >> p;
		if (p < 0)break;
		temp = temp->insert(c, p);
	}
	return in;
}

ostream& operator<< (ostream& out, const Poly& poly)
{
	Term *temp = poly.head;
	bool first = true; //表示输入为第一项
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->coef > 0 && !first ) { out << "+" << (*temp); }
		else out << (*temp); 
		if (temp->coef != 0)first = false;
	}
	out << endl;
	return out;
}

Poly Poly::operator+(Poly &p2)
{
	Poly sum;
	Term *temp1 = head->next, *temp2 = p2.head->next, *temp_sum = sum.head;
	double c; int p;
	while (temp1 != NULL && temp2 != NULL)
	{
		if (temp1->power < temp2->power)
		{
			c = temp1->coef; p = temp1->power;
			temp_sum = temp_sum->insert(c, p);
			temp1 = temp1->next;
		}
		else if (temp1->power > temp2->power)
		{
			c = temp2->coef; p = temp2->power;
			temp_sum = temp_sum->insert(c, p);
			temp2 = temp2->next;
		}
		else
		{
			c = temp1->coef + temp2->coef; p = temp1->power;
			temp_sum = temp_sum->insert(c, p);
			temp2 = temp2->next;
			temp1 = temp1->next;
		}
	}
	if (temp1 == NULL)
	{
		while (temp2 != NULL)
		{
			c = temp2->coef; p = temp2->power;
			temp_sum = temp_sum->insert(c, p);
			temp2 = temp2->next;
		}
	}
	if (temp2 == NULL)
	{
		while (temp1 != NULL)
		{
			c = temp1->coef; p = temp1->power;
			temp_sum = temp_sum->insert(c, p);
			temp1 = temp1->next;
		}
	}
	return sum;
}

Poly::~Poly()
{
	Term *temp = head, *p = temp->next;
	while (p != NULL)
	{
		delete temp;
		temp = p;
		p = p->next;
	}
	delete temp;
	delete head;
}
int main()
{
	Poly p, q, sum;
	cin >> p; cout << "此多项式为："<< p;
	cin >> q; cout << "此多项式为："<< q;
	sum = q + p;
	cout << "两多项式之和为: "<<sum;
	return 0;
}
