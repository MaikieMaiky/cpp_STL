// set大小和交换
/**
 * size();      // 返回容器中元素的数目
 * empty();     // 判断容器是否为空
 * swap(set);   // 交换两个集合容器
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
    set<int> s1;

    // 1. empty
    if (s1.empty())
    {
        cout << "s1 is empty" << endl;
    }
    else
    {
        cout << "s1 is not empty" << endl;
    }
    
    // insert
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    // 2. size
    cout << "the size of s1 is: " << s1.size() << endl;
    cout << "s1 = ";
    print_set(s1);

    // 3. swap
    set<int> s2;
    s2.insert(100);
    s2.insert(200);
    s2.insert(300);
    s2.insert(400);
    cout << "s2 = ";
    print_set(s2);


    s1.swap(s2);
    cout << "after swap: " << endl;
    cout << "s1 = ";
    print_set(s1);
    cout << "s2 = ";
    print_set(s2);
}

int main()
{
    test0();
    return 0;
}
