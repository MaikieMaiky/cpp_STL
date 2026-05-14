// vector的容量与大小
/**
 * empty();                             // 判断vector是否为空
 * capacity();                          // 返回vector的容量
 * size();                              // 返回vector中元素的个数
 * resize(int size);                    // 重新指定vector的容量，若容器变长，则以默认值填充新位置。
 *                                      // 若容器变短，则超出容器长度的元素被删除。
 * resize(int size, const T& value);    // 重新指定vector的容量，若容器变长，则以value填充新位置。
 *                                      // 若容器变短，则超出容器长度的元素被删除。
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
    // 1. 判断是否为空
    if (v1.empty())
    {
        cout << "v1 is empty" << endl;
    }
    else
    {
        cout << "v1 is not empty" << endl;
    }

    // 2. 添加元素
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }

    // 3. 查看容量和大小
    cout << "v1 capacity: " << v1.capacity() << endl;
    cout << "v1 size: " << v1.size() << endl;
    print_vector(v1);

    // 4. 重新指定大小, 以默认值填充新位置
    v1.resize(15);
    print_vector(v1);

    // 5. 重新指定大小, 以value填充新位置
    v1.resize(20, 100);
    print_vector(v1);

    // 6. 重新指定大小，超出容器长度的元素被删除
    v1.resize(3);
    print_vector(v1);
}

int main()
{
    test0();
    return 0;
}