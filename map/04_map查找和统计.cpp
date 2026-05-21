// map查找和统计
/**
 * find(key);      // 查找key是否存在，若存在返回该键的元素的迭代器，若不存在返回map.end()
 * count(key);     // 统计key的元素个数
 *
 * 对于map容器，count(key)的结果只能是0或1，因为map不允许插入重复key。
 */
#include <iostream>
#include <map>

using namespace std;

void test0()
{
    map<int, int> m1;
    m1.insert({1, 10});
    m1.insert({2, 20});
    m1.insert({3, 30});
    m1.insert({4, 40});

    // 1. find
    map<int, int>::iterator pos = m1.find(3);
    if (pos != m1.end())
    {
        cout << "find the element: key = " << pos->first << " value = " << pos->second << endl;
    }
    else
    {
        cout << "not find the element" << endl;
    }

    map<int, int>::iterator pos2 = m1.find(30);
    if (pos2 != m1.end())
    {
        cout << "find the element: key = " << pos2->first << " value = " << pos2->second << endl;
    }
    else
    {
        cout << "not find the element" << endl;
    }

    // 2. count
    int num = m1.count(3);
    cout << "the number of key 3 is: " << num << endl;
}

int main()
{
    test0();
    return 0;
}
