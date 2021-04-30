#include<iostream>
using namespace std;

//深拷贝与浅拷贝

//浅拷贝  简单的复制拷贝
//深拷贝 在堆区重新申请空间，进行拷贝操作
class Person
{
	public:
		Person(){
			cout<<"person的默认构造函数"<<endl;
		}
		Person(int age,int height){
			cout<<"person的有参构造函数"<<endl;
			m_age = age;
			m_height = new int(height);
		}
		Person(const Person& p){
			cout<<"person的拷贝构造函数"<<endl;
			//如果不利用深拷贝在堆区新建内存，会导致浅拷贝带来的重复释放堆区问题
			m_age = p.m_age;
			m_height = new int(*p.m_height);
		}

		~Person(){
			cout<<"person的析构函数"<<endl;
			if(m_height != NULL){
				delete m_height;
			}
		}

	public:
		int m_age;
		int* m_height;
};


void test01(){
	Person p1(18,180);
	Person p2(p1);
	cout<<"p1的年龄:"<<p1.m_age<<"身高："<<*p1.m_height<<endl;
	cout<<"p2的年龄:"<<p2.m_age<<"身高："<<*p2.m_height<<endl;
}

int main(){
    test01();
	return 0;
}


