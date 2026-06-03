#include "teacher.h"
#include <iostream>
using namespace std;

Teacher::Teacher() = default;

// 显示教师菜单
void Teacher::ShowMenu()
{
    cout << "==========================================" << endl;
    cout << "|      Teacher Menu                      |" << endl;
    cout << "|========================================|" << endl;
    cout << "|      1. View All Reservations          |" << endl;
    cout << "|      2. Audit Reservation              |" << endl;
    cout << "|      3. Exit                           |" << endl;
    cout << "==========================================" << endl;
    cout << "Please input your choice: ";
}

// 查看所有预约
void Teacher::ViewAllReservation()
{
    if (this->reservation_file_.reservations_.empty())
    {
        cout << "No reservation" << endl;
        return;
    }

    for (auto& reservation : this->reservation_file_.reservations_)
    {
        cout << "date: " << reservation.second["date"] << " ";
        cout << "time_slot: " << (reservation.second["time_slot"] == "1" ? "Morning" : "Afternoon") << " ";
        cout << "room_id: " << reservation.second["room_id"] << " ";
        cout << "student_id: " << reservation.second["student_id"] << " ";
        cout << "student_name: " << reservation.second["student_name"] << " ";
        cout << "status: ";
        if (reservation.second["status"] == "1")
        {
            cout << "Pending";
        }
        else if (reservation.second["status"] == "2")
        {
            cout << "Approved";
        }
        else if (reservation.second["status"] == "3")
        {
            cout << "Rejected";
        }
        else if (reservation.second["status"] == "0")
        {
            cout << "Canceled";
        }
        cout << endl;
    }
}

// 审核预约
void Teacher::AuditReservation()
{
    // 展示pending中的预约 使用map来映射
    map<int, int> reservation_map;
    int index = 1;
    for (auto& reservation : this->reservation_file_.reservations_)
    {
        if (reservation.second["status"] == "1")
        {
            reservation_map[index] = reservation.first;
            index++;
        }
    }

    if (reservation_map.empty())
    {
        cout << "No pending reservation" << endl;
        return;
    }

    for (auto& [key, value] : reservation_map)
    {
        cout << key << ". ";
        cout << "date: " << this->reservation_file_.reservations_[value]["date"] << " ";
        cout << "time_slot: " << (this->reservation_file_.reservations_[value]["time_slot"] == "1" ? "Morning" : "Afternoon") << " ";
        cout << "room_id: " << this->reservation_file_.reservations_[value]["room_id"] << " ";
        cout << "student_id: " << this->reservation_file_.reservations_[value]["student_id"] << " ";
        cout << "student_name: " << this->reservation_file_.reservations_[value]["student_name"] << " ";
        cout << "status: pending" << endl;
    }
    // 获取用户选择要审核的预约编号
    cout << "Please input the number of the reservation you want to audit: " << endl;
    int audit_number = 0;
    cin >> audit_number;
    if (audit_number < 1 || audit_number > index - 1)
    {
        cout << "Invalid input, please try again" << endl;
        return;
    }

    // 审核通过或者不通过
    cout << "Please input the status" << endl;
    cout << "1. Approved" << endl;
    cout << "2. Rejected" << endl;
    int status = 0;
    cin >> status;
    if (status < 1 || status > 2)
    {
        cout << "Invalid input, please try again" << endl;
        return;
    }
    if (status == 1)
    {
        this->reservation_file_.reservations_[reservation_map[audit_number]]["status"] = "2";
    }
    else if (status == 2)
    {
        this->reservation_file_.reservations_[reservation_map[audit_number]]["status"] = "3";
    }
    this->reservation_file_.SaveReservation();
    cout << "Audit successful" << endl;
}