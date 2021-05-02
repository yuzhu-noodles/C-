#include<iostream>
using namespace std;

//静态成员变量
class Person {
public:
	Person(string name,string ip):Name(name),IP(ip){
		total++;
	}
	static int gettotal() {
		return total;
	}
public:
	string IP;
	string Name;
private:
	static int total;//统计人的个数
};
//类外初始化
int Person::total = 0;

void test1() {
	Person p1("张三", "2021001");
	cout << "姓名：" << p1.Name << "学号：" << p1.IP << "当前学生总数：" << p1.gettotal() << endl;
	Person p2("李四", "2021002");
	cout << "姓名：" << p2.Name << "学号：" << p2.IP << "当前学生总数：" << p2.gettotal() << endl;
	Person p3("王麻子", "2021003");
	cout << "姓名：" << p3.Name << "学号：" << p3.IP << "当前学生总数：" << p3.gettotal() << endl;  //通过创建对象访问

	cout << "当前人数总数：" << Person::gettotal() << endl;  //不创建对象，通过类名访问
} 
int main()
{
	test1();
	return 0;
}


//总结：
//----------------------------------------------------------------
//静态成员变量：
//静态成员变量属于整个类所有
//静态成员变量的生命期不依赖于任何对象，为程序的生命周期
//可以通过类名 直接访问公有静态成员变量
//所有对象共享 类的静态成员变量
//可以通过对象名 访问公有静态成员变量
//类内声明，类外初始化
//静态成员变量需要在类外单独分配空间
//静态成员变量在程序内部位于 全局数据区
//----------------------------------------------------------------
//静态成员函数：
//静态成员函数属于整个类所有，没有this指针
//静态成员函数只能直接访问静态成员变量和静态成员函数
//可以通过类名直接访问类的公有静态成员函数
//可以通过对象名访问类的公有静态成员函数
//定义静态成员函数，直接使用static关键字修饰即可

