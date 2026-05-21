// map大小和交换
/**
 * size();      // 返回容器中元素的数目
 * empty();     // 判断容器是否为空
 * swap(mp);    // 交换两个map容器
 */
#include <iostream>
#include <map>

using namespace std;

void print_map(const map<int, int>& m)
{
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << (*it).first << " value = " << (*it).second << endl;
    }
    cout << endl;
}

void test0()
{
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(3, 30));

    if (m1.empty())
    {
        cout << "m1 is empty" << endl;
    }
    else
    {
        cout << "m1 is not empty" << endl;
        cout << "m1 size = " << m1.size() << endl;
    }
}

void test1()
{
    map<int, int> m1;
    m1.insert(pair<int, int>(1, 10));
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(3, 30));

    map<int, int> m2;
    m2.insert(pair<int, int>(4, 40));
    m2.insert(pair<int, int>(5, 50));
    m2.insert(pair<int, int>(6, 60));

    cout << "before swap:" << endl;
    cout << "m1 = " << endl;
    print_map(m1);
    cout << "m2 = " << endl;
    print_map(m2);

    m1.swap(m2);

    cout << "after swap:" << endl;
    cout << "m1 = " << endl;
    print_map(m1);
    cout << "m2 = " << endl;
    print_map(m2);
}

int main()
{
    test0();
    test1();
    return 0;
}
