#include "computer_room_reservation_system.h"
#include <iostream>
using namespace std;


// 显示菜单 文本全部使用英文
void ComputerRoomReservationSystem::ShowMenu()
{
    cout << "==========================================" << endl;
    cout << "|       Computer Room Reservation System |" << endl;
    cout << "|=========================================" << endl;
    cout << "|        1. Student Login                |" << endl;
    cout << "|        2. Teacher Login                |" << endl;
    cout << "|        3. Admin Login                  |" << endl;
    cout << "|        4. Exit                         |" << endl;
    cout << "==========================================" << endl;
    cout << "Please input your choice: ";
}

// 退出系统
void ComputerRoomReservationSystem::ExitSystem()
{
    cout << "Thank you for using the computer room reservation system\n";
    system("pause");
    system("cls");
    exit(0);
}