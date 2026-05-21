// map排序
/**
 * map<T1, T2, Compare> mp;     // 创建map容器时指定排序规则
 *
 * map容器默认按照key从小到大排序。
 * 利用仿函数可以改变map容器的排序规则。
 * 内置数据类型可以使用greater<T>来生成仿函数
 */
#include <iostream>
#include <map>

using namespace std;

class my_compare
{
public:
    bool operator()(int v1, int v2) const
    {
        return v1 > v2; // 降序
    }
};

void print_map(const map<int, int, my_compare>& m)
{
    for (map<int, int, my_compare>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << endl;
}

void test0()
{
    // 在创建时就要指定排序规则
    map<int, int, my_compare> m1;
    // map<int, int, greater<int>> m1;
    m1.insert({1, 10});
    m1.insert({2, 20});
    m1.insert({3, 30});
    m1.insert({4, 40});
    m1.insert({5, 50});

    cout << "m1 = " << endl;
    print_map(m1);
}

int main()
{
    test0();
    return 0;
}
