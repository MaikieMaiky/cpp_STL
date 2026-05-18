// set指定排序规则 - 内置类型
/**
 * set<T, Compare> st;     // 创建set容器时指定排序规则
 *
 * 仿函数示例：
 * class my_compare
 * {
 * public:
 *     bool operator()(int v1, int v2) const
 *     {
 *         return v1 > v2; // 降序
 *     }
 * };
 *
 * set<int, my_compare> st; // 对内置数据类型指定排序规则
 */
#include <iostream>
#include <set>

using namespace std;

// 仿函数
class my_compare
{
public:
    bool operator()(int v1, int v2) const
    {
        return v1 > v2; // 降序
    }
};

void print_set(const set<int, my_compare>& s)
{
    for (set<int, my_compare>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test0()
{
    // 在创建时就要指定排序规则
    set<int, my_compare> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(50);
    
    cout << "s1 = ";
    print_set(s1);
}

int main()
{
    test0();
    return 0;
}
