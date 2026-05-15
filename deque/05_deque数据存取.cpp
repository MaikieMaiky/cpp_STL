// deque的数据存取
/**
 * at(idx);                                 // 返回索引idx所指的数据
 * operator[];                              // 返回索引idx所指的数据
 * front();                                 // 返回首元素
 * back();                                  // 返回尾元素
 */
#include <iostream>
#include <deque>

using namespace std;

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
    for (int i = 0; i < d.size(); i++)
    {
        cout << d.at(i) << " ";
    }
    cout << endl;

    cout << "d = ";
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    cout << "d.front() = " << d.front() << endl;
    cout << "d.back() = " << d.back() << endl;
}

int main()
{
    test0();
    return 0;
}