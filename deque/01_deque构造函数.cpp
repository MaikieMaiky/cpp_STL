// deque的构造函数
/**
 * deque<T> deq;                         // 默认构造形式
 * deque(beg, end);                      // 构造函数将[beg, end)区间中的元素拷贝给本身。(迭代器区间)
 * deque(n, elem);                       // 构造函数将n个elem拷贝给本身。
 * deque(const deque &deq);              // 拷贝构造函数
 */
#include <iostream>
#include <deque>

using namespace std;

// 使用const deque保证只读不修改
void print_deque(const deque<int>& d)
{
    // 因为只读不修改，因此需要使用const_iterator
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test0()
{
    // 1. 默认构造
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    cout << "d1 = ";
    print_deque(d1);

    // 2. 迭代器区间拷贝
    deque<int> d2(d1.begin(), d1.end());
    cout << "d2 = ";
    print_deque(d2);

    // 3. 将n个elem拷贝给本身。
    deque<int> d3(10, 66);
    cout << "d3 = ";
    print_deque(d3);

    // 4. 拷贝构造
    deque<int> d4(d3);
    cout << "d4 = ";
    print_deque(d4);
}

int main()
{
    test0();
    return 0;
}