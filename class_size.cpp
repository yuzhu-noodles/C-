#include<iostream>
#include<algorithm>
using namespace std;

class Student{
};

void test1(){
	Student S1;
	//编译器给每个对象分配一个字节的空间，是为了区分每个空对象占内存的地址
	//每一个空对象都有独一无二的地址
	cout<<"size of S1:"<<sizeof(S1)<<endl;
}

class Person{
	int m_A;                 //非静态成员变量，属于类对象上 此时 size of Person = 4
	static int m_B ;         //静态成员变量，不属于类对象上，此时size of Person 不会变化
	void func(){}            //非静态成员函数，不属于类对象上，此时size of Person不会变化
	static void func1(){}    //静态成员函数，不属于类对象上，此时size of Person不会变化
};

int Person:: m_B = 0; //静态成员变量需要类内声明，类外初始化
void test2(){

	Person p;
	cout<<"size of p:"<<sizeof(p)<<endl;
}
int main(){
	//test1();
	test2();
	return 0;
}
