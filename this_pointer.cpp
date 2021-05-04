#include<iostream>
using namespace std;

//this指针  是隐含在每一个非静态成员函数中的指针，无需定义

class Person{
public:
	//1.解决命名冲突，当形参和对象成员命名冲突时，使用this指针区分
	Person(int age){
		this->age = age;  //this指针指向被调用成员函数所述的对象 
    }

	//2.返回对象本身
	Person& AgeAdd(Person p){    //以值的方式会返回一个新对象，所以得是引用
		this->age += p.age;
		return *this;    //this是指向p2的指针，所以*this指向p2的本体
	}
	int age;
};

void test(){
	Person p1(100);
	cout<<"p1的年龄:"<<p1.age<<endl;

	Person p2(100);
	p2.AgeAdd(p1).AgeAdd(p1);
	cout<<"p2的年龄:"<<p2.age<<endl;
}

int main(){
	test();
	return 0;
}


