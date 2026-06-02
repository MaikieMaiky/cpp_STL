#ifndef __IDENTITY
#define __IDENTITY

#include <string>
using namespace std;

// 身份基类
class Identity
{
public:
    // 显示菜单
    virtual void ShowMenu() = 0;

    // 姓名
    string name_ = "default";

    // 密码
    string password_ = "123456";
};


#endif  // __IDENTITY
