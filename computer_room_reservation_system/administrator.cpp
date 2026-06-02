#include "administrator.h"
#include <iostream>
#include "global_file.h"
#include <fstream>
using namespace std;

// 显示子菜单
void Administrator::ShowMenu()
{
    cout << "==========================================" << endl;
    cout << "|      Administrator Menu                |" << endl;
    cout << "|=========================================" << endl;
    cout << "|      1. Add Account                    |" << endl;
    cout << "|      2. View Account                   |" << endl;
    cout << "|      3. View Machine Room              |" << endl;
    cout << "|      4. Clear Reservation              |" << endl;
    cout << "|      5. Exit                           |" << endl;
    cout << "==========================================" << endl;
    cout << "Please input your choice: ";
}


// 添加账号 先不考虑重复账号 保留注释以便后续实现
void Administrator::AddAccount()
{
    // 1.choose the type of account: Teacher or Student
    cout << "Please input the type of account: " << endl;
    cout << "1. Teacher" << endl;
    cout << "2. Student" << endl;


    // 2.input the account information
    string filename = "";
    string tip = "";
    int id = 0;
    string name;
    string password;
    int type = 0;
    cin >> type;
    if (type == 1)
    {
        // 添加教师账号
        filename = kTeacherFile;
        tip = "Please input the teacher id: ";
    }
    else if (type == 2)
    {
        // 添加学生账号
        filename = kStudentFile;
        tip = "Please input the student id: ";
    }
    else
    {
        cout << "Invalid input, please try again" << endl;
        return;
    }
    // 输入账号信息
    cout << tip;
    cin >> id;
    cout << "Please input the name: ";
    cin >> name;
    cout << "Please input the password: ";
    cin >> password;

    // 3.save the account information to the file
    // 打开文件 append
    ofstream ofs;
    ofs.open(filename, ios::app);
    if (!ofs.is_open())
    {
        cout << "File open error" << endl;
        return;
    }
    ofs << id << "," << name << "," << password << endl;
    ofs.close();
    cout << "Add account successfully" << endl;
    return;
}
// 查看账号
void Administrator::ViewAccount()
{
}

// 查看机房
void Administrator::ViewMachineRoom()
{
}

// 清空预约
void Administrator::ClearReservation()
{
}