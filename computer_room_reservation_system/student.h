#ifndef __STUDENT
#define __STUDENT

#include "identity.h"
#include "machine_room.h"
#include <vector>
using namespace std;


class Student : public Identity
{
public:
    // 默认构造
    Student();

    // 有参构造
    Student(string name, string password, int id);

    // 获取机房信息
    void GetMachineRoomInfo();

    // 显示菜单
    virtual void ShowMenu() override;

    // 申请预约 
    void ApplyReservation();

    // 查看自身预约
    void ViewSelfReservation();

    // 查看所有预约
    void ViewAllReservation();
    
    // 取消预约
    void CancelReservation();
    
    // 学号
    int id_ = 0;

    // 机房信息
    vector<MachineRoom> machine_room_;

};

#endif  // __STUDENT
