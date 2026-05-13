// string的构造函数
/**
 * string(); // 创建一个空的字符串 例如: string str;
 * string(const char* s); // 使用字符串s初始化
 * string(const string& str); // 使用一个string对象初始化另一个string对象
 * string(int n, char c); // 使用n个字符c初始化
 * 
 */
#include <iostream>
#include <string>

using namespace std;

void test0()
{
    // 1. 默认构造
    string s1; 

    // 2. 使用字符串s初始化
    const char* str = "hello world";
    string s2(str); // 使用字符串s初始化

    // 3. 使用一个string对象初始化另一个string对象
    string s3(s2);

    // 4. 使用n个字符c初始化
    string s4(10, 'a');

    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
}

int main()
{
    test0();
    return 0;
}