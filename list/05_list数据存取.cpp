// list的数据存取
/**
 * front(); // 返回第一个元素。
 * back(); // 返回最后一个元素。
 * 不可以使用at和[],因为list不支持随机访问。
 */
#include <iostream>
#include <list>

using namespace std;

void test0()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_front(100);
    l1.push_front(200);
    l1.push_front(300);

    // 1. front()
    cout << "the first element of l1 is: " << l1.front() << endl;

    // 2. back()
    cout << "the last element of l1 is: " << l1.back() << endl;

    // 3. at(can not be used)
    // cout << "the first element of l1 is: " << l1.at(0) << endl;

    // 4. [](can not be used)
    // cout << "the first element of l1 is: " << l1[0] << endl;
}

int main()
{
    test0();
    return 0;
}