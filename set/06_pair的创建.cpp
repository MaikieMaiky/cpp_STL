// pair的创建
/**
 * pair<T1, T2> p(value1, value2);              // 方式一：通过构造函数创建pair
 * pair<T1, T2> p = make_pair(value1, value2);  // 方式二：通过make_pair创建pair
 * 
 * pair.first   // 获取第一个元素
 * pair.second  // 获取第二个元素
 */
#include <iostream>
#include <set>
#include <utility>

using namespace std;

void test0()
{
    // 1.构造函数创建
    pair<string, int> p1("GG bond", 18);
    cout << "p1.first = " << p1.first << ", p1.second = " << p1.second << endl;

    // 2. make_pair创建
    pair<string, int> p2 = make_pair("Xi Yangyang", 88);
    cout << "p2.first = " << p2.first << ", p2.second = " << p2.second << endl;
}

int main()
{
    test0();
    return 0;
}
