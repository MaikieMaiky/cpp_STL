#include "student.h"
#include <iostream>
#include "global_file.h"
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

void print_machine_room(const MachineRoom &machine_room)
{
    cout << "Machine Room ID: " << machine_room.room_id << " Capacity: " << machine_room.capacity << endl;
}

// 默认构造
Student::Student()
{
    GetMachineRoomInfo();
}

// 有参构造
Student::Student(string name, string password, int id) : Identity(name, password), id_(id)
{
    GetMachineRoomInfo();
}

// 获取机房信息
void Student::GetMachineRoomInfo()
{
    string filename = kMachineRoomFile;
    ifstream ifs;
    ifs.open(filename, ios::in);
    if (!ifs.is_open())
    {
        cout << "File open error" << endl;
        return;
    }
    
    machine_room_.clear();
    string line;
    while (getline(ifs, line))
    {
        stringstream ss(line);
        MachineRoom machine_room;
        char comma;
        ss >> machine_room.room_id >> comma;
        ss >> machine_room.capacity;
        machine_room_.push_back(machine_room);
    }
    ifs.close();
    return;
}
// 显示学生菜单
void Student::ShowMenu()
{
    cout << "==========================================" << endl;
    cout << "|      Student Menu                      |" << endl;
    cout << "|========================================|" << endl;
    cout << "|      1. Apply Reservation              |" << endl;
    cout << "|      2. View Self Reservation          |" << endl;
    cout << "|      3. View All Reservations          |" << endl;
    cout << "|      4. Cancel Reservation             |" << endl;
    cout << "|      5. Exit                           |" << endl;
    cout << "==========================================" << endl;
    cout << "Please input your choice: ";
}

// 申请预约
void Student::ApplyReservation()
{
    // 1. 显示机房信息
    for_each(machine_room_.begin(), machine_room_.end(), print_machine_room);
    // 2. 选择机房
    cout << "Please input the ID of the machine room you want to apply for: " << endl;
    int room_id = 0;
    cin >> room_id;
    if (room_id < 1 || room_id > 3)
    {
        cout << "Invalid input, please try again" << endl;
        return;
    }
    // 3. 选择日期
    cout << "Please input the date you want to apply for: " << endl;
    cout << "1. Monday" << endl;
    cout << "2. Tuesday" << endl;
    cout << "3. Wednesday" << endl;
    cout << "4. Thursday" << endl;
    cout << "5. Friday" << endl;
    int date = 0;
    cin >> date;
    if (date < 1 || date > 5)
    {
        cout << "Invalid input, please try again" << endl;
        return;
    }
    // 4. 选择时段
    cout << "Please input the time slot you want to apply for: " << endl;
    cout << "1. Morning" << endl;
    cout << "2. Afternoon" << endl;
    int time_slot = 0;
    cin >> time_slot;
    if (time_slot < 1 || time_slot > 2)
    {
        cout << "Invalid input, please try again" << endl;
        return;
    }
    // 5. 显示预约成功 审核中
    cout << "Reservation successful, please wait for approval" << endl;

    // 6. 追加到预约文件
    this->reservation_file_.reservations_[this->reservation_file_.reservations_.size() + 1] = {
        {"date", to_string(date)},
        {"time_slot", to_string(time_slot)},
        {"room_id", to_string(room_id)},
        {"student_id", to_string(id_)},
        {"student_name", name_},
        {"status", "1"}
    };
    this->reservation_file_.SaveReservation();
    return;
}

// 查看自身预约
void Student::ViewSelfReservation()
{
    for (auto& reservation : this->reservation_file_.reservations_)
    {
        if (reservation.second["student_id"] == to_string(id_))
        {
            cout << "date: " << reservation.second["date"] << " ";
            cout << "time_slot: " << (reservation.second["time_slot"] == "1" ? "Morning" : "Afternoon") << " ";
            cout << "room_id: " << reservation.second["room_id"] << " ";
            cout << "student_id: " << reservation.second["student_id"] << " ";
            cout << "student_name: " << reservation.second["student_name"] << " ";
            cout << "status: ";
            if (reservation.second["status"] == "1")
            {
                cout << "Pending" << endl;
            }
            else if (reservation.second["status"] == "2")
            {
                cout << "Approved" << endl;
            }
            else if (reservation.second["status"] == "3")
            {
                cout << "Rejected" << endl;
            }
            else if (reservation.second["status"] == "0")
            {
                cout << "Canceled" << endl;
            }
            cout << endl;
        }
    }    
}
// 查看所有预约
void Student::ViewAllReservation()
{
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
            cout << "Pending" << endl;
        }
        else if (reservation.second["status"] == "2")
        {
            cout << "Approved" << endl;
        }
        else if (reservation.second["status"] == "3")
        {
            cout << "Rejected" << endl;
        }
        else if (reservation.second["status"] == "0")
        {
            cout << "Canceled" << endl;
        }
        cout << endl;
    }
}

// 取消预约
void Student::CancelReservation()
{
    // 使用map存储个人预约和全体预约之间编号的映射
    map<int, int> reservation_map;
    int index = 1;
    for (auto& reservation : this->reservation_file_.reservations_)
    {
        // 只显示审核中和审核通过的预约
        if (reservation.second["student_id"] == to_string(id_))
        {
            if (reservation.second["status"] == "1" || reservation.second["status"] == "2")
            {
                reservation_map[index] = reservation.first;
                index++;
            }
        }
    }
    for (auto& [key, value] : reservation_map)
    {
        cout << key << ". ";
        cout << "date: " << this->reservation_file_.reservations_[value]["date"] << " ";
        cout << "time_slot: " << (this->reservation_file_.reservations_[value]["time_slot"] == "1" ? "Morning" : "Afternoon") << " ";
        cout << "room_id: " << this->reservation_file_.reservations_[value]["room_id"] << " ";
        cout << "student_id: " << this->reservation_file_.reservations_[value]["student_id"] << " ";
        cout << "student_name: " << this->reservation_file_.reservations_[value]["student_name"] << " ";
        cout << "status: ";
        if (this->reservation_file_.reservations_[value]["status"] == "1")
        {
            cout << "Pending" << endl;
        }
        else if (this->reservation_file_.reservations_[value]["status"] == "2")
        {
            cout << "Approved" << endl;
        }
    }

    // 获取用户选择要取消的预约编号
    cout << "Please input the number of the reservation you want to cancel: " << endl;
    int cancel_number = 0;
    cin >> cancel_number;
    if (cancel_number < 1 || cancel_number > index - 1)
    {
        cout << "Invalid input, please try again" << endl;
        return;
    }
    this->reservation_file_.reservations_[reservation_map[cancel_number]]["status"] = "0";
    this->reservation_file_.SaveReservation();
    cout << "Cancel reservation successfully" << endl;
}