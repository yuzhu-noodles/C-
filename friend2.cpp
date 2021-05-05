#include<iostream>
using namespace std;

//类做友元
//成员函数做友元

class MyHome;
class GoodGay{   //创造一个好基友类
	public:
		GoodGay();
		//void Visit1();
		void Visit2();
	private:
		MyHome * myhome;
};

class MyHome{
	//friend class GoodGay;//类做友元
    friend void GoodGay::Visit2();
	public:
		MyHome();
		string SittingRoom;  //客厅公有，可以访问
	private:
		string BedRoom;      //卧室私有，允许后才可以访问
};

MyHome::MyHome(){
	SittingRoom = "客厅";
	BedRoom = "卧室";
}
GoodGay::GoodGay(){
	myhome = new MyHome;
}
//void GoodGay::Visit1(){
//	cout<<"GoodGay类正在访问："<<myhome->SittingRoom<<endl;
//	cout<<"GoodGat类正在访问："<<myhome->BedRoom<<endl;
//}
void GoodGay::Visit2(){
	cout<<"GoodGay的Visit2正在访问："<<myhome->BedRoom<<endl;
}

//类做友元测试
//void test(){
//	GoodGay GG;
//	GG.Visit1();
//}

//成员函数做友元测试
void test2(){
	GoodGay GG;
	GG.Visit2();
}
int main(){
	//test1();
	test2();
	return 0;
}
