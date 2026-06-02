#ifndef __ADMINISTRATOR
#define __ADMINISTRATOR

#include "identity.h"
#include <vector>
#include "teacher.h"
#include "student.h"
using namespace std;

class Administrator : public Identity
{
public:
    // 默认构造
    Administrator();

    // 有参构造
    Administrator(string name, string password);

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

    // 初始化容器
    void InitVector();

    // 教师容器
    vector<Teacher> teacher_;

    // 学生容器
    vector<Student> student_;
};

#endif  // __ADMINISTRATOR
