// string的比较函数
/**
 * int compare(const string& s) const; // 与字符串s比较
 * int compare(const char* s) const; // 与字符串s比较
 * 
 */
#include <iostream>
#include <string>

using namespace std;

void test0()
{
    string s1 = "xello";
    string s2 = "hello";
    if (s1.compare(s2) == 0)
    {
        cout << "s1 == s2" << endl;
    }
    else if (s1.compare(s2) > 0)
    {
        cout << "s1 > s2" << endl;
    }
    else
    {
        cout << "s1 < s2" << endl;
    }
}

int main()
{
    test0();
    return 0;
}