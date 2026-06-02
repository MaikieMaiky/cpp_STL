#ifndef __STUDENT
#define __STUDENT

#include "identity.h"
using namespace std;


class Student : public Identity
{
public:
    // 默认构造
    Student();

    // 有参构造
    Student(string name, string password, int id) : Identity(name, password), id_(id) {}

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
};

#endif  // __STUDENT
