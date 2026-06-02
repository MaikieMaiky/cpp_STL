#include "computer_room_reservation_system.h"
#include <iostream>
#include <fstream>
#include "global_file.h"
using namespace std;

// login global function
// 参数1: 文件名 参数2：操作身份类型
void Login(string filename, int type)
{
    ifstream ifs;
    ifs.open(filename, ios::in);
    // 文件打开失败
    if (!ifs.is_open())
    {
        cout << "File open error" << endl;
        return;
    }

    // 文件打开成功
    // 接收用户信息
    int id = 0;
    string name;
    string password;
    switch (type)
    {
        case 1:
            // 学生登录
            cout << "Please input your student id: ";
            cin >> id;
            break;
        case 2:
            // 教师登录
            cout << "Please input your teacher id: ";
            cin >> id;
            break;
    }
    // 输入用户名和密码
    cout << "Please input your name: ";
    cin >> name;
    cout << "Please input your password: ";
    cin >> password;

    // 身份验证
    switch (type)
    {
        case 1:
            // 学生身份验证
            break;
        case 2:
            // 教师身份验证
            break;
        case 3:
            // 管理员身份验证
            break;
    }

    ifs.close();
}


int main()
{
    ComputerRoomReservationSystem crms;
    system("cls");
    while (true)
    {
        crms.ShowMenu();
        int choice = 0;
        cin >> choice;
        switch (choice)
        {
            case 1:
                // 学生登录
                cout << "Student Login" << endl;
                Login(kStudentFile, 1);
                break;
            case 2:
                // 教师登录
                cout << "Teacher Login" << endl;
                Login(kTeacherFile, 2);
                break;
            case 3:
                // 管理员登录
                cout << "Admin Login" << endl;
                Login(kAdminFile, 3);
                break;
            case 4:
                // 退出系统
                crms.ExitSystem();
                break;
            default:
                cout << "Invalid input, please try again" << endl;
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}