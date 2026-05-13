// string的字串获取
/**
 * string substr(int pos = 0, int n = npos) const; // 返回从pos开始的n个字符组成的字符串
 * 
 */
#include <iostream>
#include <string>

using namespace std;

void test0()
{
    string str = "LeiJun@gmail.com";

    // 取出用户名
    int pos = str.find('@');
    string username = str.substr(0, pos);
    cout << "username: " << username << endl;
}

int main()
{
    test0();
    return 0;
}