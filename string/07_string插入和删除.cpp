// string的插入和删除
/**
 * string& insert(int pos, const char* s); // 在pos位置插入字符串s
 * string& insert(int pos, const string& str); // 在pos位置插入字符串str
 * string& insert(int pos, int n, char c); // 在pos位置插入n个字符c
 * string& erase(int pos = 0, int n = npos); // 删除从pos开始的n个字符
 * 
 */
#include <iostream>
#include <string>

using namespace std;

void test0()
{
    string str = "hello";

    // 1. 插入
    str.insert(1, "111");
    cout << "str = " << str << endl;
    
    // 2. 删除
    str.erase(1, 3);
    cout << "str = " << str << endl;
}

int main()
{
    test0();
    return 0;
}