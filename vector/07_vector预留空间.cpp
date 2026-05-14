// vector预留空间
/**
 * reserve(int len); // 预留len个元素的容量
 */
#include <iostream>
#include <vector>

using namespace std;

// 通过提前预留大块空间 减少vector扩容次数 提高效率
void test0()
{
    vector<int> v;
    
    // 开关注释 对比是否预留空间对扩容次数的影响
    // v.reserve(100000);

    // 记录每次扩容的地址 如果地址发生变化 则说明发生了扩容
    int* p = NULL;
    int count = 0;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            count++;
        }
    }
    cout << "the number of times of expansion: " << count << endl;
}

int main()
{
    test0();
    return 0;
}