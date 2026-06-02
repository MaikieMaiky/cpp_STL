#ifndef __ADMINISTRATOR
#define __ADMINISTRATOR

#include "identity.h"
using namespace std;

class Administrator : public Identity
{
public:
    // 默认构造
    Administrator();

    // 有参构造
    Administrator(string name, string password) : Identity(name, password) {}

    // 显示菜单
    virtual void ShowMenu() override;

    // 添加账号
    void AddAccount();

    // 查看账号
    void ViewAccount();
    
    // 查看机房
    void ViewMachineRoom();

    // 清空预约
    void ClearReservation();
};

#endif  // __ADMINISTRATOR
