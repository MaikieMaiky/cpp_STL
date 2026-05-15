// deque的插入和删除
/**
 * 两端插入/删除
 * push_back(elem);                          // 在容器尾部添加一个数据
 * push_front(elem);                         // 在容器头部插入一个数据
 * pop_back();                               // 删除容器最后一个数据
 * pop_front();                              // 删除容器第一个数据
 *
 * 指定位置操作(pos处需要输入迭代器)
 * insert(pos, elem);                        // 在pos位置插入一个elem元素的拷贝，返回新数据的位置。
 * insert(pos, n, elem);                     // 在pos位置插入n个elem数据，无返回值。
 * insert(pos, beg, end);                    // 在pos位置插入[beg, end)区间的数据，无返回值。
 * erase(pos);                               // 删除pos位置的数据，返回下一个数据的位置。
 * erase(beg, end);                          // 删除[beg, end)区间的数据，返回下一个数据的位置。
 * clear();                                  // 清空容器中的所有数据
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
    // 尾插
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    // 头插
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);
    cout << "d1 = ";
    print_deque(d1);

    // 尾删
    d1.pop_back();
    // 头删
    d1.pop_front();
    cout << "d1 = ";
    print_deque(d1);

    // 指定位置插入
    d1.insert(d1.begin() + 1, 1000);
    cout << "d1 = ";
    print_deque(d1);

    // 指定位置插入n个elem数据
    d1.insert(d1.end() - 1, 2, 2000);
    cout << "d1 = ";
    print_deque(d1);

    // 指定位置插入[beg, end)区间的数据
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    d1.insert(d1.begin() + 1, d2.begin(), d2.end());
    cout << "d1 = ";
    print_deque(d1);

    // 指定位置删除
    d1.erase(d1.begin());
    cout << "d1 = ";
    print_deque(d1);

    // 删除指定位置的元素
    d1.erase(d1.begin() + 1);
    cout << "d1 = ";
    print_deque(d1);

    // 删除指定位置的元素
    d1.erase(d1.begin() + 1, d1.begin() + 3);
    cout << "d1 = ";
    print_deque(d1);

    // 清空容器中的所有数据
    d1.clear();
    cout << "d1 = ";
    print_deque(d1);
}

int main()
{
    test0();
    return 0;
}