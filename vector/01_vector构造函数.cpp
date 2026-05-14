// vector的构造函数
/**
 * vector();                                        // 无参构造函数
 * vector(int n, const T& value);                   // 拷贝n个value到vector中
 * vector(const vector& v);                         // 拷贝构造函数
 * vector(InputIterator first, InputIterator last); // 复制[first,
 * last)范围的元素到vector中，一般写作vector(v.begin(), v.end())
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
    // 1. 无参构造
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    print_vector(v1);

    // 2. 拷贝n个value到vector中
    vector<int> v2(10, 1);
    print_vector(v2);

    // 3. 拷贝构造函数
    vector<int> v3(v1);
    print_vector(v3);
    
    // 4. 复制[first, last)范围的元素到vector中
    vector<int> v4(v1.begin(), v1.end());
    print_vector(v4);
}

int main()
{
    test0();
    return 0;
}