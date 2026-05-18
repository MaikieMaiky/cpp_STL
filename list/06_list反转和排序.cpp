// list的反转和排序
/**
 * reverse();   // 反转
 * sort();      // 排序 - 成员函数
 * 对于不支持随机访问的迭代器，容器会提供相应的排序成员函数
 * 默认升序，可以通过传入回调函数，实现降序排序
 * 对于自定义数据类型，标准库并没有提供默认实现，需要传入回调函数，实现自定义的排序规则（见07_list自定义排序）
 */
#include <iostream>
#include <list>

using namespace std;


bool my_compare(int num1, int num2)
{
    return num1 > num2;
}

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
    l1.push_front(100);
    l1.push_front(200);
    l1.push_front(300);
    cout << "l1 = ";
    print_list(l1);

    // reverse
    l1.reverse();
    cout << "after reverse, l1 = ";
    print_list(l1);

    // sort
    l1.sort();
    cout << "after sort, l1 = ";
    print_list(l1);

    // 降序 sort
    l1.sort(my_compare);
    cout << "after sort(my_compare), l1 = ";
    print_list(l1);

}

int main()
{
    test0();
    return 0;
}