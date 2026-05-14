// vector的插入和删除
/**
 * push_back(const T& value);                       // 在末尾添加元素
 * pop_back();                                      // 删除末尾的元素
 * insert(iterator pos, const T& value);            // 在pos位置插入value
 * insert(iterator pos, int n, const T& value);     // 在pos位置插入n个value
 * erase(iterator pos);                             // 删除pos位置的元素
 * erase(iterator first, iterator last);            // 删除[first, last)范围的元素
 * clear();                                         // 清空vector
 */
#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test0()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {   
        v.push_back(i);
    }
    print_vector(v);

    // 1. 在末尾添加元素
    v.push_back(100);
    print_vector(v);
    
    // 2. 删除末尾的元素
    for (int i = 0; i < 5; i++)
    {
        v.pop_back();
    }
    print_vector(v);

    // 3. 在pos位置插入value
    v.insert(v.begin(), 100);
    print_vector(v);
    
    // 4. 在pos位置插入n个value
    v.insert(v.begin(), 2, 88);
    print_vector(v);

    // 5. 删除pos位置的元素
    v.erase(v.begin() + 2);
    print_vector(v);

    // 6. 删除[first, last)范围的元素
    v.erase(v.begin() + 1, v.begin() + 3);
    print_vector(v);

    // 7. 清空vector
    v.clear();
    print_vector(v);

}

int main()
{
    test0();
    return 0;
}