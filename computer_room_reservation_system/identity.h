#ifndef __IDENTITY
#define __IDENTITY

#include <string>
using namespace std;

// 身份基类
class Identity
{
public:

    // 默认构造
    Identity() = default;

    // 有参构造
    Identity(string name, string password) : name_(name), password_(password) {}
    virtual ~Identity() = default;

    // 显示菜单
    virtual void ShowMenu() = 0;

    // 姓名
    string name_ = "default";

    // 密码
    string password_ = "123456";
};


#endif  // __IDENTITY
