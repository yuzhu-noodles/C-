#include<iostream>
using namespace std;

class Person
{
	public:
		//构造函数
		Person(){
			cout<<"person无参构造函数"<<endl;
		}
		Person(int a){
			cout<<"person有参构造函数"<<endl;
            age =a;
		}
		Person(const Person &p){                //引用是为了节省内存，const是为了防止篡改
			cout<<"person拷贝构造函数"<<endl;
			age = p.age;
		}

		~Person(){
			cout<<"person析构函数"<<endl;
		}
		int age;

};

void test1()
{
	//1,括号法
//	Person p1;         //调用默认构造时 不加()   加了括号会被编译器误认为函数声明
//	Person p2(10);
//	Person p3(p2);

	//2.显示法
//	Person p1;
//	Person p2 = Person(10); //有参构造
//	cout<<"hahah"<<endl;
//	Person p3 = Person(p2); //拷贝构造

	//匿名对象  特点：当前执行结束后，系统会立即回收掉匿名对象
//	Person(10);
//	cout<<"heihei"<<endl;
//	Person(p3);  错误
//	不能利用拷贝构造函数 初始化匿名对象  ，编译器会认为Person(p3) == Person p3  对象重定义

	//3，隐式转换法
	Person p4 = 10;   //相当于Person p4 = Person(10)
	Person p5 = p4;   //相当于Person p5 = Person(p4)
}


void dowork2(Person p){
}

Person dowork3(){
	Person p;
	cout<<(int*)&p<<endl;
	return p;
}
void test2(){
	//拷贝函数的调用时机
	//1.使用创建完毕的对象初始化一个新对象
//	Person p1;
//	Person p2(p1);

	//2.以值传递方式给函数传参
//	Person p2;
//	dowork(p2);   // 实参传给形参  会调用拷贝构造函数  相当于Person p = p1;

	//3.值方式返回局部对象
	Person p3 = dowork3();
	cout<<(int*)&p3<<endl;

}
int main(){
	test2();
	return 0;
}

