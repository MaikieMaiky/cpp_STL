// string的拼接函数
/**
 * string& operator+=(const char* str);             // 重载+=操作符
 * string& operator+=(const char c);                // 重载+=操作符
 * string& operator+=(const string& str);           // 重载+=操作符
 * string& append(const char* s);                   // 把字符串s连接到当前字符串结尾
 * string& append(const char* s, int n);            // 把字符串s的前n个字符连接到当前字符串结尾
 * string& append(const string& s);                 // 把字符串s连接到当前字符串结尾
 * string& append(const string& s, int pos, int n); // 把字符串s从pos开始的n个字符连接到当前字符串结尾
 * string& append(int n, char c);                   // 在当前字符串结尾添加n个字符c
 * 
 */
#include <iostream>
#include <string>

using namespace std;

void test0()
{
    string s1 = "hello";
    s1 += " world";

    string s2 = "hello";
    s2 += 'b';

    string s3 = "hello";
    s3 += s1;
    
    string s4 = "hello";
    s4.append(" world");
    
    string s5 = "hello";
    s5.append(" world", 3);

    string s6 = "hello";
    s6.append(s1);

    string s7 = "hello";
    s7.append(s1, 5, 6);

    string s8 = "hello";
    s8.append(5, 'b');

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
    cout << "s5 = " << s5 << endl;
    cout << "s6 = " << s6 << endl;
    cout << "s7 = " << s7 << endl;
    cout << "s8 = " << s8 << endl;
}

int main()
{
    test0();
    return 0;
}