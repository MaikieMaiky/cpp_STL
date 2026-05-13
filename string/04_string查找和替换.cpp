// string的查找和替换
/**
 * int find(const string& str, int pos = 0) const;      // 查找str第一次出现位置,从pos开始查找
 * int find(const char* s, int pos = 0) const;          // 查找s第一次出现位置,从pos开始查找
 * int find(const char* s, int pos, int n) const;       // 查找s前n个字符第一次出现位置,从pos开始查找
 * int find(const char c, int pos = 0) const;           // 查找c第一次出现位置,从pos开始查找
 * int rfind(const string& str, int pos = npos) const;  // 查找str最后一次出现位置,从pos开始查找
 * int rfind(const char* s, int pos = npos) const;      // 查找s最后一次出现位置,从pos开始查找
 * int rfind(const char* s, int pos, int n) const;      // 查找s前n个字符最后一次出现位置,从pos开始查找
 * int rfind(const char c, int pos = npos) const;       // 查找c最后一次出现位置,从pos开始查找
 * string& replace(int pos, int n, const string& str);  // 替换从pos开始的n个字符为str
 * string& replace(int pos, int n, const char* s);      // 替换从pos开始的n个字符为s
 * 
 */
#include <iostream>
#include <string>

using namespace std;

// 1. find
void test0()
{
    string str = "abcdefgde";
    int pos = str.find("de");

    cout << "pos = " << pos << endl;

    pos = str.rfind("de");
    cout << "pos = " << pos << endl;


}


// 2. replace
void test1()
{
    string str = "abcdefgde";
    // 把1-3位置的字符替换为1111这个字符串
    str.replace(1, 3, "1111");
    cout << "str = " << str << endl;

    
}

int main()
{
    test1();
    return 0;
}