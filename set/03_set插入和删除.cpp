// set插入和删除
/**
 * insert(elem);       // 在容器中插入元素
 * erase(pos);         // 删除pos迭代器所指的元素，返回下一个元素的迭代器
 * erase(beg, end);    // 删除区间[beg, end)的所有元素，返回下一个元素的迭代器
 * erase(elem);        // 删除容器中值为elem的元素
 * clear();            // 清除所有元素
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
    // 1. insert
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(50);
    cout << "s1 = ";
    print_set(s1);

    // 2. erase(pos)
    s1.erase(s1.begin());
    cout << "s1 = ";
    print_set(s1);

    // 3. erase(beg, end)
    s1.erase(--s1.end(), s1.end());
    cout << "s1 = ";
    print_set(s1);

    // 4. erase(elem)
    s1.erase(20);
    cout << "s1 = ";
    print_set(s1);

    // 5. clear
    s1.clear();
    cout << "s1 = ";
    print_set(s1);
}

int main()
{
    test0();
    return 0;
}
