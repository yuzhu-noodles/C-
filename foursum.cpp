#include<iostream>
using namespace std;


class Person
{
public:
	void Dispaly()
	{
		cout << "name:" << name << "age:" << age << endl;
	}
public:
	char* name;
	int age;
};

void test()
{
	Person p;
	p.name = "liqi";
	p.age = 12;
	p.Dispaly();
}
//void Person::Dispaly1()
//{
//	cout << "name:" << name << "age:" << age << endl;
//}
int main()
{
	test();
	//int a = 0;
	//int& b = a;
	//cout << a<<"address:" << &a << endl;
	//cout << b<<"address:" << &b << endl;

	//int& c = b;
	//cout << "b,address:" << &c << endl;

	//int a = 1;
	//const int& b = a;
	//
	//cout << a << endl;
	//cout << b << endl;
	//const int a = 1;
	//const int& b = a;
	//const int& c = b;
	//cout << c;

	return 0;
}