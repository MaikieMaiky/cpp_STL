// list的赋值和交换
/**
 * list& operator=(const list &lst);    // 重载等号操作符
 * assign(beg, end);                    // 将[beg, end)区间中的数据拷贝赋值给本身。
 * assign(n, elem);                     // 将n个elem拷贝赋值给本身。
 * swap(lst);                           // 将lst与本身的元素互换。
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
    list<int> l1;
    // 1. assign(n, elem)
    l1.assign(5, 66);
    cout << "l1 = ";
    print_list(l1);

    list<int> l2;
    // 2. assign(beg, end)
    l2.assign(l1.begin(), l1.end());
    cout << "l2 = ";
    print_list(l2);

    list<int> l3;
    // 3. operator=
    l3 = l1;
    cout << "l3 = ";
    print_list(l3);

    list<int> l4;
    // 4. assign(n, elem)
    l4.assign(3, 88);
    cout << "l4 = ";
    print_list(l4);
    
    // 5. swap
    l1.swap(l4);
    cout << "after swap" << endl;
    cout << "l1 = ";
    print_list(l1);
    cout << "l4 = ";
    print_list(l4);
    
}

int main()
{
    test0();
    return 0;
}