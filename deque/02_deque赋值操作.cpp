// deque的赋值操作
/**
 * deque& operator=(const deque &deq);            // 重载=操作符
 * assign(beg, end);                              // 将[beg, end)区间中的数据拷贝赋值给本身(迭代器区间)
 * assign(n, elem);                               // 将n个elem拷贝赋值给本身
 */
#include <iostream>
#include <deque>

using namespace std;

void print_deque(const deque<int>& d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test0()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    cout << "d1 = ";
    print_deque(d1);

    // 1. 重载=操作符
    deque<int> d2;
    d2 = d1;
    cout << "d2 = ";
    print_deque(d2);
    
    // 2. 将[beg, end)区间中的数据拷贝赋值给本身(迭代器区间)
    deque<int> d3;
    d3.assign(d1.begin(), d1.end());
    cout << "d3 = ";
    print_deque(d3);
    
    // 3. 将n个elem拷贝赋值给本身
    deque<int> d4;
    d4.assign(10, 66);
    cout << "d4 = ";
    print_deque(d4);
}

int main()
{
    test0();
    return 0;
}