// string的赋值函数
/**
 * string& operator=(const char* s);    // 使用字符串s赋值
 * string& operator=(const string& s);  // 使用一个string对象赋值
 * string& operator=(char c);           // 使用字符c赋值
 * assign(const char* s);               // 使用字符串s赋值
 * assign(const char* s, int n);        // 使用字符串s的前n个字符赋值
 * assign(const string& s);             // 使用一个string对象赋值
 * assign(int n, char c);               // 使用n个字符c赋值
 *
 */
#include <iostream>
#include <string>

using namespace std;

void test0()
{
    string s1;
    s1 = "hello world";

    string s2;
    s2 = s1;

    string s3;
    s3 = 'a';

    string s4;
    s4.assign("hello world");

    string s5;
    s5.assign("hello world", 5);
    
    string s6;
    s6.assign(s1);

    string s7;
    s7.assign(10, 'a');

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    cout << "s4 = " << s4 << endl;
    cout << "s5 = " << s5 << endl;
    cout << "s6 = " << s6 << endl;
    cout << "s7 = " << s7 << endl;
}

int main()
{
    test0();
    return 0;
}