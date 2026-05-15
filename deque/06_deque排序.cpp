// deque的排序
/**
 * sort(iterator beg, iterator end); // 对[beg, end)区间内的元素进行排序
 */
#include <iostream>
#include <deque>
#include <algorithm>

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
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    cout << "d = ";
    print_deque(d);

    // 排序 默认升序
    sort(d.begin(), d.end());
    cout << "d = ";
    print_deque(d);
}

int main()
{
    test0();
    return 0;
}