#include "computer_room_reservation_system.h"
#include <iostream>
using namespace std;

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
                break;
            case 2:
                // 教师登录
                cout << "Teacher Login" << endl;
                break;
            case 3:
                // 管理员登录
                cout << "Admin Login" << endl;
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