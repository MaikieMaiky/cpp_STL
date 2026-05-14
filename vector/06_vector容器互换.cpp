// vector容器互换
/**
 * swap(vector& vec); // 将vec与当前vector进行交换
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
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << "v1 = ";
    print_vector(v1);

    vector<int> v2;
    for (int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    cout << "v2 = ";
    print_vector(v2);

    // 互换
    v1.swap(v2);
    cout << "v1 = ";
    print_vector(v1);
    cout << "v2 = ";
    print_vector(v2);
}

// 实际应用 
void test1()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
    cout << "v capacity: " << v.capacity() << endl;
    cout << "v size: " << v.size() << endl;

    // size缩小为3 capacity不变
    v.resize(3);
    cout << "after resize" << endl;
    cout << "v capacity: " << v.capacity() << endl;
    cout << "v size: " << v.size() << endl;

    // 内存收缩 vector<int>(不写名字)(v) 匿名对象 拷贝构造函数复制原对象的size 并以此为capacity 然后与原对象交换指向 匿名函数负责释放原对象内存
    vector<int>(v).swap(v);
    cout << "after swap" << endl;
    cout << "v capacity: " << v.capacity() << endl;
    cout << "v size: " << v.size() << endl;
}

int main()
{
    // test0();
    test1();
    return 0;
}