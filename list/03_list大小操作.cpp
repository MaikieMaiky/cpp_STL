// list的大小操作
/**
 * size();              // 返回容器中元素的个数
 * empty();             // 判断容器是否为空
 * resize(num);         // 重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
 * resize(num, elem);   // 重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
 * 
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
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    cout << "the size of l1 is: " << l1.size() << endl;
    cout << "l1 = ";
    print_list(l1);

    // 1. resize(num)
    l1.resize(10);
    cout << "the size of l1 is: " << l1.size() << endl;
    cout << "l1 = ";
    print_list(l1);

    // 2. resize(num, elem)
    l1.resize(15, 100);
    cout << "the size of l1 is: " << l1.size() << endl;
    cout << "l1 = ";
    print_list(l1);
}

int main()
{
    test0();
    return 0;
}