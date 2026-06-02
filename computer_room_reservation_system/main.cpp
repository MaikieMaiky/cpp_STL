#include "computer_room_reservation_system.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "global_file.h"
#include "identity.h"
#include "administrator.h"
using namespace std;



// 管理员子界面菜单
void ManagerMenu(Identity* &manager)
{
    system("cls");
    while (true)
    {
        manager->ShowMenu();

        // 转回子类指针调用特有函数
        Administrator* admin = (Administrator*)manager;
        int choice = 0;
        cin >> choice;
        switch (choice)
        {
            case 1:
                // 添加账号
                cout << "Add Account" << endl;
                admin->AddAccount();
                break;
            case 2:
                // 查看账号
                cout << "View Account" << endl;
                admin->ViewAccount();
                break;
            case 3:
                // 查看机房
                cout << "View Machine Room" << endl;
                admin->ViewMachineRoom();
                break;
            case 4:
                // 清空预约
                cout << "Clear Reservation" << endl;
                admin->ClearReservation();
                break;
            case 5:
                // 退出系统 释放堆空间
                delete manager;
                manager = nullptr;
                cout << "Exit successfully" << endl;
                return;
                break;
            default:
                cout << "Invalid input, please try again" << endl;
                break;
        }
        system("pause");
        system("cls");
    }
}

// login global function
// 参数1: 文件名 参数2：操作身份类型
void Login(string filename, int type)
{
    // 创建父类指针 用于接收子类指针
    Identity* manager = nullptr;

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
    getline(cin >> ws, name);
    cout << "Please input your password: ";
    cin >> password;

    // 身份验证
    switch (type)
    {
        case 1:
        {
            // 学生身份验证
            // 获取每行输入 以逗号进行分隔 与用户输入的id,name,password进行比较
            string line;
            int file_id = 0;
            string file_name;
            string file_password;
            while (getline(ifs, line))
            {
                // 以逗号进行分隔
                // 字符串流 可以当作一个流 从流中读取数据
                stringstream ss(line);
                char comma;
                ss >> file_id >> comma;
                getline(ss, file_name, ',');
                getline(ss, file_password);

                // 三项信息全部匹配则登录成功
                if (id == file_id && name == file_name && password == file_password)
                {
                    cout << "Student login successful" << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Student login failed: invalid account or password" << endl;
            break;
        }
        case 2:
        {
            // 教师身份验证
            // 获取每行输入 以逗号进行分隔 与用户输入的id,name,password进行比较
            string line;
            int file_id = 0;
            string file_name;
            string file_password;
            while (getline(ifs, line))
            {
                // 以逗号进行分隔
                stringstream ss(line);
                char comma;
                ss >> file_id >> comma;
                getline(ss, file_name, ',');
                getline(ss, file_password);

                // 三项信息全部匹配则登录成功
                if (id == file_id && name == file_name && password == file_password)
                {
                    cout << "Teacher login successful" << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Teacher login failed: invalid account or password" << endl;
            break;
        }
        case 3:
        {
            // 管理员身份验证
            // 获取每行输入 与用户输入的name,password进行比较
            string line;
            string file_name;
            string file_password;
            while (getline(ifs, line))
            {
                // 以逗号进行分隔
                stringstream ss(line);
                getline(ss, file_name, ',');
                getline(ss, file_password);

                // 两项信息全部匹配则登录成功
                if (name == file_name && password == file_password)
                {
                    cout << "Admin login successful" << endl;
                    manager = new Administrator(name, password);
                    system("pause");
                    system("cls");
                    ManagerMenu(manager);
                    return;
                }
            }
            cout << "Admin login failed: invalid account or password" << endl;
            break;
        }
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
