// set查找和统计
/**
 * find(key);      // 查找key是否存在，若存在返回该键的元素的迭代器，若不存在返回set.end()
 * count(key);     // 统计key的元素个数
 *
 * 对于set容器，count(key)的结果只能是0或1，因为set不允许插入重复元素。
 */
#include <iostream>
#include <set>

using namespace std;

void test0()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(50);

    // 1. find
    set<int>::iterator pos = s1.find(30);
    if (pos != s1.end())
    {
        cout << "find the element: " << *pos << endl;
    }
    else
    {
        cout << "not find the element" << endl;
    }

    set<int>::iterator pos2 = s1.find(300);
    if (pos2 != s1.end())
    {
        cout << "find the element: " << *pos2 << endl;
    }
    else
    {
        cout << "not find the element" << endl;
    }
    

    // 2. count
    int num = s1.count(30);
    cout << "the number of 30 is: " << num << endl;
}

int main()
{
    test0();
    return 0;
}
