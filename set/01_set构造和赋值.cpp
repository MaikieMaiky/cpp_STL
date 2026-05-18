// set构造和赋值
/**
 * set<T> st;                       // 默认构造函数
 * set(const set &st);              // 拷贝构造函数
 * set& operator=(const set &st);   // 重载等号操作符
 *
 * set容器特点：
 * 1. 所有元素在插入时会自动被排序
 * 2. set属于关联式容器，底层结构通常为二叉树
 * 3. set不允许容器中有重复元素
 */
#include <iostream>
#include <set>

using namespace std;

void print_set(const set<int>& s)
{
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test0()
{
    // 1. 默认构造
    set<int> s1;

    // set容器只能通过insert插入元素
    // insert 
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    // 插入重复元素，不会插入成功
    s1.insert(30);
    s1.insert(40);
    cout << "s1 = ";
    print_set(s1);

    // 2. 拷贝构造
    set<int> s2(s1);
    cout << "s2 = ";
    print_set(s2);

    // 3. 赋值
    set<int> s3;
    s3 = s1;
    cout << "s3 = ";
    print_set(s3);
}

int main()
{
    test0();
    return 0;
}
