// map插入和删除
/**
 * insert({key, value});                            // 在容器中插入元素 key一样则插入失败
 * insert(make_pair(key, value));                   // 在容器中插入元素 key一样则插入失败
 * insert(pair<int, int>(key, value));              // 在容器中插入元素 key一样则插入失败
 * insert(map<int, int>::value_type(key, value));   // 在容器中插入元素 key一样则插入失败
 * operator[](key) = value;                         // 通过[]方式插入/修改元素 key一样则覆盖value
 * erase(pos);                                      // 删除pos迭代器所指的元素，返回下一个元素的迭代器
 * erase(beg, end);                                 // 删除区间[beg, end)的所有元素，返回下一个元素的迭代器
 * erase(key);                                      // 删除容器中key对应的元素
 * clear();                                         // 清除所有元素
 */
#include <iostream>
#include <map>

using namespace std;

void print_map(const map<int, int>& m)
{
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    cout << endl;
}

void test0()
{
    map<int, int> m1;

    // 1. insert
    m1.insert(pair<int, int>(1, 10));
    m1.insert(make_pair(2, 20));
    m1.insert(map<int, int>::value_type(3, 30));
    m1[4] = 40;
    cout << "m1 = " << endl;
    print_map(m1);

    // 2. erase(pos)
    m1.erase(m1.begin());
    cout << "m1 = " << endl;
    print_map(m1);

    // 3. erase(beg, end)
    m1.erase(++m1.begin(), m1.end());
    cout << "m1 = " << endl;
    print_map(m1);

    // 4. erase(key)
    m1.erase(2);
    cout << "m1 = " << endl;
    print_map(m1);

    // 5. clear
    m1.clear();
    cout << "m1 = " << endl;
    print_map(m1);
}

int main()
{
    test0();
    return 0;
}
