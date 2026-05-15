// deque的大小操作
/**
 * size();                               // 返回容器中元素的个数
 * empty();                              // 判断容器是否为空
 * resize(num);                          // 重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
 * resize(num, elem);                    // 重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
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

    // 1. 返回容器中元素的个数
    cout << "d1.size() = " << d1.size() << endl;

    // 2. 重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
    d1.resize(15);
    cout << "d1 = ";
    print_deque(d1);
    cout << "d1.size() = " << d1.size() << endl;

    // 3. 重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
    d1.resize(20, 22);
    cout << "d1 = ";
    print_deque(d1);
    cout << "d1.size() = " << d1.size() << endl;

    // 4. 判断容器是否为空
    if (d1.empty())
    {
        cout << "d1 is empty" << endl;
    }
    else
    {
        cout << "d1 is not empty" << endl;
    }
}

int main()
{
    test0();
    return 0;
}