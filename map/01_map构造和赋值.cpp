// map构造和赋值
/**
 * map<T1, T2> mp;                      // 默认构造函数
 * map(const map &mp);                  // 拷贝构造函数
 * map& operator=(const map &mp);       // 重载等号操作符
 *
 * map容器特点：
 * 1. map中所有元素都是pair
 * 2. pair中第一个元素为key，起到索引作用，第二个元素为value
 * 3. 所有元素都会根据元素的key自动排序
 */
#include <iostream>
#include <map>

using namespace std;

void print_map(const map<int, int>& m)
{
    for (auto &p : m)
    {
        cout << "key = " << p.first << " value = " << p.second << endl;
    }
    cout << endl;
}

void test0()
{
    // 1. 默认构造
    map<int, int> m1;

    // map容器插入数据需要使用pair
    m1.insert({1, 10});
    m1.insert(pair<int, int>(2, 20));
    m1.insert(pair<int, int>(3, 30));
    m1[4] = 40;
    cout << "m1 = " << endl;
    print_map(m1);

    // 2. 拷贝构造
    map<int, int> m2(m1);
    cout << "m2 = " << endl;
    print_map(m2);

    // 3. 赋值
    map<int, int> m3;
    m3 = m1;
    cout << "m3 = " << endl;
    print_map(m3);
}

int main()
{
    test0();
    return 0;
}
