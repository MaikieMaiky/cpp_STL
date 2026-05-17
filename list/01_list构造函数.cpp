// list的构造函数
/**
 * list<T> lst;             // 默认构造函数
 * list(beg, end);          // 构造函数将[beg, end)区间中的元素拷贝给本身。
 * list(n, elem);           // 构造函数将n个elem拷贝给本身。
 * list(const list &lst);   // 拷贝构造函数
 */
#include <iostream>
#include <list>

using namespace std;

void print_list(const list<int>& l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test0()
{
    // 1. 默认构造
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    cout << "l1 = ";
    print_list(l1);

    // 2. 将[beg, end)区间中的元素拷贝给本身。
    list<int> l2(l1.begin(), l1.end());
    cout << "l2 = ";
    print_list(l2);

    // 3. 构造函数将n个elem拷贝给本身。
    list<int> l3(3, 66);
    cout << "l3 = ";
    print_list(l3);

    // 4. 拷贝构造
    list<int> l4(l3);
    cout << "l4 = ";
    print_list(l4);
}

int main()
{
    test0();
    return 0;
}