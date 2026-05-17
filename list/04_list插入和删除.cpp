// list的插入和删除
/**
 * push_back(elem);             // 尾插
 * pop_back();                  // 尾删
 * push_front(elem);            // 头插
 * pop_front();                 // 头删
 * insert(pos, elem);           // 在pos位置插入elem元素的拷贝，返回新数据的位置。
 * insert(pos, n, elem);        // 在pos位置插入n个elem元素的拷贝，返回新数据的位置。
 * insert(pos, beg, end);       // 在pos位置插入[beg, end)区间中的数据，返回新数据的位置。
 * erase(beg, end);             // 删除[beg, end)区间中的数据，返回下一个数据的位置。
 * erase(pos);                  // 删除pos位置的数据，返回下一个数据的位置。
 * remove(elem);                // 删除容器中所有与elem值匹配的元素。
 * clear();                     // 清空
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
    l1.push_back(20);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_front(100);
    l1.push_front(200);
    l1.push_front(300);
    cout << "l1 = ";
    print_list(l1);

    // 2. pop_back
    l1.pop_back();
    l1.pop_front();
    cout << "l1 = ";
    print_list(l1);

    // 3. insert(pos, elem)
    l1.insert(l1.begin(), 1000);
    cout << "l1 = ";
    print_list(l1);

    // 4. insert(pos, n, elem)
    l1.insert(l1.end(), 2, 2000);
    cout << "l1 = ";
    print_list(l1);

    // 5. erase(pos)
    l1.erase(l1.begin());
    cout << "l1 = ";
    print_list(l1);

    // 6. remove(elem)
    l1.remove(20);
    cout << "l1 = ";
    print_list(l1);

    // 7. clear()
    l1.clear();
    cout << "l1 = ";
    print_list(l1); 
}

int main()
{
    test0();
    return 0;
}