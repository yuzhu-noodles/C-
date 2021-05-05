#include<iostream>
using namespace std;

class Home{
	friend void goodGay(Home& h);
	public:
	Home(){
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
	public:
		string m_SittingRoom;
	private:
		string m_BedRoom;
};

void goodGay(Home& h){
	cout<<"goodGay全局函数正在访问："<<h.m_SittingRoom<<endl;
	cout<<"goodGay全局函数正在访问："<<h.m_BedRoom<<endl;
}
//全局函数做友元
void test1(){
	Home h;
	goodGay(h);
}


int main(){
	test1();
	return 0;
}

