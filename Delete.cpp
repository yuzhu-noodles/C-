#include<iostream>
using namespace std;

//delete 和 deltet[]区别
//1、对于简单类型 
//int* p = new int [5]
//delete 和 delete[] 没有区别
//原因：在分配简单类型内存时，内存大小确定，系统根据记忆进行管理，并且不需要进行析构

//2、对于自定义数据类型
//通过new申请了一个数组，在释放时需要做两件事：1释放最初申请的空间，2通过析构函数进行清理
//delete只释放指针指向的内存空间，但是只调用了数组第一个元素的析构函数
//delete 会调用每个数组元素的析构函数
class Person{
  public:
    Person(){
      cout<<"Person的构造函数"<<endl;
    }
    ~Person(){
      cout<<"Person的析构函数"<<endl;
    }
};

void test(){
  Person* p1 = new Person[5];

  //delete p1;
  cout<<hex<<p1<<endl;
  delete[] p1;   

  Person* p2 = new Person[5];
  cout<<hex<<p2<<endl;
}

int main(){
  test();
  return 0;
}
