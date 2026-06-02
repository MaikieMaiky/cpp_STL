#include "teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher() = default;

// 显示教师菜单
void Teacher::ShowMenu()
{
    cout << "==========================================" << endl;
    cout << "|      Teacher Menu                      |" << endl;
    cout << "|=========================================|" << endl;
    cout << "|      1. View All Reservations          |" << endl;
    cout << "|      2. Audit Reservation              |" << endl;
    cout << "|      3. Exit                           |" << endl;
    cout << "==========================================" << endl;
    cout << "Please input your choice: ";
}
