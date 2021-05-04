#include<iostream>
using namespace std;

//空指针访问成员函数
class Student{
	public:
		void ShowClassName(){
			cout<<"This is a Person class"<<endl;
		}
		void ShowStudentAge(){
			if(this == NULL)
				return;     //对this进行判断，提高代码健壮性
			cout<<"Student Age:"<<m_Age<<endl; //编译器在编译时会默认this->m_Age;
		}
		int m_Age;
};

void test(){
	Student* s = NULL;
	s->ShowClassName();   //空指针可以调用成员函数
	s->ShowStudentAge();  //如果成员函数使用this指针，则会报错

	//this指针指向被调用成员所述的对象，我们定义了一个空指针，this都没有指向一个确切的对象实体，访问空指针的成员肯定会报错
}

int main(){
	test();
	return 0;
}

