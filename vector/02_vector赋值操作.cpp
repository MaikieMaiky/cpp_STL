// vector的赋值操作
/**
 * vector& operator=(const vector& v);              // 重载=操作符
 * assign(int n, const T& value);                   // 复制n个value到vector中
 * assign(InputIterator first, InputIterator last); // 复制[first, last)范围的元素到vector中,一般写作assign(v.begin(), v.end())
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
    // 无参构造
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    print_vector(v1);

    // 重载=操作符
    vector<int> v2;
    v2 = v1;
    print_vector(v2);
    
    // 复制n个value到vector中
    vector<int> v3;
    v3.assign(10, 100);
    print_vector(v3);

    // 复制[first, last)范围的元素到vector中
    vector<int> v4;
    v4.assign(v1.begin(), v1.end());
    print_vector(v4);
}

int main()
{
    test0();
    return 0;
}