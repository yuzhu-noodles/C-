#include <iostream>
using namespace std;
#define MAX 1000

struct Person  //联系人结构体
{
    string m_name;
    int m_sex;
    int m_age;
    string m_phone;
    string m_addr;
};
struct addressbooks  //通讯录结构体
{ 
    struct Person personarray[MAX];   //联系人数组
    int m_size;                       //联系人个数
};

void showMenu()  //界面菜单
{
    cout << "***  李琪的通讯录   ***" << endl;
    cout << "***  1、添加联系人  ***" << endl;
    cout << "***  2、显示联系人  ***" << endl;
    cout << "***  3、删除联系人  ***" << endl;
    cout << "***  4、查找联系人  ***" << endl;
    cout << "***  5、修改联系人  ***" << endl;
    cout << "***  6、清空联系人  ***" << endl;
    cout << "***  0、退出通讯录  ***" << endl;
}
void addperson(addressbooks* abs)   //添加联系人
{
    //判断通讯录是否满了
    if (abs->m_size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }
    else
    {
        //姓名
        string name;
        cout << "请输入姓名: " << endl;
        cin >> name;
        abs->personarray[abs->m_size].m_name = name;

        //性别
        cout << "请输入性别： " << endl;
        cout << "1---男" << endl;
        cout << "2---女" << endl;
        int sex = 0;
        
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)  //若果输入的是1/2，可以退出循环，因为输入的正确值，如果有误，重新输入
            {
                abs->personarray[abs->m_size].m_sex = sex;
                break;
            }
            cout << "输入错误，请重新输入" << endl;
        }
        //年龄
        cout << "请输入年龄" << endl;
        int age = 0;
        cin >> age;
        abs->personarray[abs->m_size].m_age = age;

        //电话
        cout << "请输入联系电话： " << endl;
        string phone;
        cin >> phone;
        abs->personarray[abs->m_size].m_phone = phone;

        //住址
        cout << "请输入家庭住址" << endl;
        string address;
        cin >> address;
        abs->personarray[abs->m_size].m_addr = address;

        //更新通讯录人数
        abs->m_size++;
        cout << "添加成功" << endl;
        system("pause");
        system("cls");  //清屏
    }
}
//显示联系人
void showperson(addressbooks* abs)
{
    if (abs->m_size == 0)
    {
        cout << "当前记录为空" << endl;

    }
    else
    {
        for (int i = 0; i < abs->m_size; i++)
        {
            cout << "姓名： " << abs->personarray[i].m_name << "\t";
            cout << "性别： " << (abs->personarray[i].m_sex ==1?"男":"女")<< "\t";   //三目运算符
            cout << "年龄： " << abs->personarray[i].m_age << "\t";
            cout << "电话： " << abs->personarray[i].m_phone << "\t";
            cout << "地址： " << abs->personarray[i].m_addr << endl;

        }          
    }
    system("pause");
    system("cls");
}
//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1

int isexist(addressbooks* abs, string name)
{
    for (int i = 0; i < abs->m_size; i++)
    {
        if (abs->personarray[i].m_name == name)
        {
            return i;  //找到，返回下标
        }         
    }
    return -1;
}
void deleteperson(addressbooks* abs)
{
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;
    int ret = isexist(abs, name);  //ret != -1查到了

    if (ret != -1)
    {
        for (int j = ret; j < abs->m_size; j++)
        {
            abs->personarray[j] = abs->personarray[j + 1]; //数据迁移
            
        }
        abs->m_size--;
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}
//查找联系人
void findperson(addressbooks* abs)
{
    cout << "请输入要查找的联系人：" << endl;
    string name;
    cin >> name;
    int ret = isexist(abs, name);
    if (ret != -1)
    {
        cout << "姓名： " << abs->personarray[ret].m_name << "\t";
        cout << "性别： " << (abs->personarray[ret].m_sex == 1 ? "男" : "女") << "\t";   //三目运算符
        cout << "年龄： " << abs->personarray[ret].m_age << "\t";
        cout << "电话： " << abs->personarray[ret].m_phone << "\t";
        cout << "地址： " << abs->personarray[ret].m_addr << endl;
    }
    else
    {
        cout << "查无此人！" << endl;
    }
    system("pause");
    system("cls");
}
//修改指定联系人信息
void modifyperson(addressbooks* abs)
{
    cout << "请输入要修改的联系人：" << endl;
    string name;
    cin >> name;
    int ret = isexist(abs, name);
    if (ret != -1)
    {
        //姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personarray[ret].m_name = name;
        //性别
        int sex = 0;
        cout << "请输入性别：" << endl;
        cout << "1---男" << endl;
        cout << "2---女" << endl;
        cin >> sex;
        while (true)
        {
            if (sex == 1 || sex == 2)
            {
                abs->personarray[ret].m_sex = sex;
                break;
            }
            else
            {
                cout << "输入错误，请重新输入" << endl;
            }
        } 
        //年龄
        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs->personarray[ret].m_age = age;
        //电话
        cout << "请输入电话：" << endl;
        string phone;
        cin>> phone;
        abs->personarray[ret].m_phone = phone;

        //住址
        cout << "请输入地址：" << endl;
        string addr;
        cin >> addr;
        abs->personarray[ret].m_addr = addr;

        cout << "恭喜您修改成功" << endl;

    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}
void cleanperson(addressbooks* abs)
{
    abs->m_size = 0;   //设置当前记录联系人数量置为0，做逻辑清空操作
    cout << "通讯录已清空" << endl;
    system("pause");
    system("cls");

}
int main()
{
    //创建通讯录结构体变量
    addressbooks abs;
    abs.m_size = 0;   //初始化个数
    
    int select = 0;
    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1:  //添加联系人
            addperson(&abs);
            break;
        case 2:  //显示联系人
            showperson(&abs);
            break;
        case 3:  //删除联系人
            deleteperson(&abs);
            break;
        case 4:  //查找联系人
            findperson(&abs);
            break;
        case 5:  //修改联系人
            modifyperson(&abs);
            break;
        case 6:  //清空联系人
            cleanperson(&abs);
            break;
        case 0:  //退出通讯录
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }
    system("pause");
    return 0;
}


