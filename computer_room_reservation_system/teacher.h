#ifndef __TEACHER
#define __TEACHER

#include "identity.h"
using namespace std;


class Teacher : public Identity
{
public:
    // 默认构造
    Teacher();

    // 有参构造
    Teacher(string name, string password, int id) : Identity(name, password), id_(id) {}

    // 显示菜单
    virtual void ShowMenu() override;

    // 查看所有预约
    void ViewAllReservation();

    // 审核预约
    void AuditReservation();
    
    // 职工号
    int id_ = 0;
};


#endif  // __TEACHER
