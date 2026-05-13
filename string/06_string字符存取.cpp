// string的字符存取
/**
 * char& operator[](int n); // 通过[]方式取字符
 * char& at(int n);         // 通过at方法获取字符
 * 
 */
#include <iostream>
#include <string>

using namespace std;

void test0()
{
    // 1. []
    string str = "hello";
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;
    
    // 2. at
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << " ";
    }
    cout << endl;

    // 3. 修改
    str[0] = 'b';
    str.at(1) = 'b';
    cout << "str = " << str << endl;
}

int main()
{
    test0();
    return 0;
}