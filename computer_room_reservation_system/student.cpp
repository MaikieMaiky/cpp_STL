#include "student.h"
#include <iostream>
using namespace std;

Student::Student() = default;

// 显示学生菜单
void Student::ShowMenu()
{
    cout << "==========================================" << endl;
    cout << "|      Student Menu                      |" << endl;
    cout << "|=========================================|" << endl;
    cout << "|      1. Apply Reservation              |" << endl;
    cout << "|      2. View Self Reservation          |" << endl;
    cout << "|      3. View All Reservations          |" << endl;
    cout << "|      4. Cancel Reservation             |" << endl;
    cout << "|      5. Exit                           |" << endl;
    cout << "==========================================" << endl;
    cout << "Please input your choice: ";
}
