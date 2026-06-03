#include "reservation_file.h"
#include <fstream>
#include <sstream>
#include "global_file.h"
#include <iostream>
using namespace std;

ReservationFile::ReservationFile()
{
    LoadReservation();
}

ReservationFile::~ReservationFile()
{
    SaveReservation();
}

void ReservationFile::LoadReservation()
{
    reservations_.clear();
    ifstream ifs;
    ifs.open(kReservationFile, ios::in);
    if (!ifs.is_open())
    {
        cout << "File open error" << endl;
        return;
    }
    
    string line;
    // 1. 按照逗号分割 拿出每一部分
    int index = 1;
    while (getline(ifs, line))
    {
        stringstream ss(line);
        string date;
        string time_slot;
        string room_id;
        string student_id;
        string student_name;
        string status;
        getline(ss, date, ',');
        getline(ss, time_slot, ',');
        getline(ss, room_id, ',');
        getline(ss, student_id, ',');
        getline(ss, student_name, ',');
        getline(ss, status, ',');

        // 2. 每一部分按照冒号分割 拿出每一部分
        string key;
        string value;
        map<string, string> reservation;

        int pos = 0;
        pos = date.find(':', 0);
        key = date.substr(0, pos);
        value = date.substr(pos + 1, date.size() - pos - 1);
        reservation.insert({key, value});
        
        pos = time_slot.find(':', 0);
        key = time_slot.substr(0, pos);
        value = time_slot.substr(pos + 1, time_slot.size() - pos - 1);
        reservation.insert({key, value});
        
        pos = room_id.find(':', 0);
        key = room_id.substr(0, pos);
        value = room_id.substr(pos + 1, room_id.size() - pos - 1);
        reservation.insert({key, value});
        
        pos = student_id.find(':', 0);
        key = student_id.substr(0, pos);
        value = student_id.substr(pos + 1, student_id.size() - pos - 1);
        reservation.insert({key, value});
        
        pos = student_name.find(':', 0);
        key = student_name.substr(0, pos);
        value = student_name.substr(pos + 1, student_name.size() - pos - 1);
        reservation.insert({key, value});
        
        pos = status.find(':', 0);
        key = status.substr(0, pos);
        value = status.substr(pos + 1, status.size() - pos - 1);
        reservation.insert({key, value});
        
        reservations_.insert({index, reservation});
        index++;
    }
    ifs.close();

    // 测试
    for (auto& reservation : reservations_)
    {
        cout << reservation.first << " ";
        for (auto& [key, value] : reservation.second)
        {
            cout << key << ": " << value << " ";
        }
        cout << endl;
    }
}

void ReservationFile::SaveReservation()
{
    // 1. 打开文件并truncate
    ofstream ofs;
    ofs.open(kReservationFile, ios::trunc);
    if (!ofs.is_open())
    {
        cout << "File open error" << endl;
        return;
    }
    // 2. 写入数据
    for (auto& reservation : reservations_)
    {
        for (auto& [key, value] : reservation.second)
        {
            ofs << key << ":" << value << ",";
        }
        ofs << endl;
    }   
    ofs.close();
    return;
}
