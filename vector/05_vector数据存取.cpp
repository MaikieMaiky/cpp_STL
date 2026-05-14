// vector的数据存取
/**
 * at(int idx);          // 通过索引访问元素
 * operator[];           // 通过索引访问元素
 * front();              // 访问第一个元素
 * back();               // 访问最后一个元素
 */
#include <iostream>
#include <vector>

using namespace std;

void test0()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 1. 通过索引访问元素
    cout << "v[0] = " << v[0] << endl;
    cout << "v.at(2) = " << v.at(2) << endl;
    
    // 2. 访问第一个元素
    cout << "the first element is " << v.front() << endl;

    // 3. 访问最后一个元素
    cout << "the last element is " << v.back() << endl;
}

int main()
{
    test0();
    return 0;
}