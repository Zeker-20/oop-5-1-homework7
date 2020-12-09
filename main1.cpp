
#include"iostream"
using namespace std;
/*************************************基类***************************************/
class Base
{
protected:
	int b;
private:
	int c;
public:
	int a;
	static int count;
	Base(int m, int n, int k)
	{
		a = m;
		b = n;
		c = k;
		count++;
		cout << "构造函数被调用" << endl;
	}
	~Base()
	{
		cout << "Base析构函数被调用" << endl;
		getchar();
	}

	void print()
	{
		cout << a << " " << b << " " << c << endl;
	}
	static int statistic()
	{
		return count;
	}

};
int Base::count = 0;
/*************************************Deriived1***************************************/
class Derived1 :public Base
{
private:
	int x;
public:
	Derived1(int y, int m, int n, int k) :Base(m, n, k)
	{
		x = y;
		count++;
		cout << x << endl;
		print();
		cout << x << a << endl;
	}
	~Derived1()
	{
		cout << "Derived1析构函数被调用" << endl;
		getchar();
	}
};
/*************************************Deriived2***************************************/
class Derived2 :private Base
{
private:
	int x;
	Base d2;
public:
	Derived2(int y, int m, int n, int k) :Base(m, n, k),d2(m,n,k)
	{
		x = y;
		count++;
		cout << x << endl;
		d2.print();
	}
	~Derived2()
	{
		cout << "Derived2析构函数被调用" << endl;
		getchar();
	}
};
/*************************************Deriived3***************************************/
class Derived3 :protected Base
{
private:
	int x;
	Base d3;
public:
	Derived3(int y, int m, int n, int k) :Base(m, n, k),d3(m,n,k)
	{
		x= y;
		count++;
		cout << x << endl;
		d3.print();
	}
	~Derived3()
	{
		cout << "Derived3析构函数被调用" << endl;
		getchar();
	}
};
/*************************************main***************************************/

int main()
{
	int b;
	Base hy(0, 0, 0);//统计对象个数的一个对象
	Derived1 D(1, 2, 3, 4);
	Derived2 E(1, 2, 3, 4);
	Derived3 F(1, 2, 3, 4);
	cout << hy.statistic() << endl;//全局变量的输出有问题
	return 0;
}
