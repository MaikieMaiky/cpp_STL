// set和multiset的区别
/**
 * set不允许容器中有重复元素
 * multiset允许容器中有重复元素
 *
 * set插入数据的同时会返回插入结果，表示插入是否成功
 * pair<set<T>::iterator, bool> ret = st.insert(elem);
 * pair用于表示一对值，在这里first表示插入的元素的迭代器，second表示插入是否成功
 *
 * multiset不会检测数据是否重复，因此可以插入重复数据
 * multiset<T> mst;
 * mst.insert(elem);
 */
#include <iostream>
#include <set>

using namespace std;

void test0()
{
    // set
    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    
    pair<set<int>::iterator, bool> ret = s1.insert(20);
    if (ret.second)
    {
        cout << "insert success" << endl;
    }
    else
    {
        cout << "insert failed" << endl;
    }

    // print set
    for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // multiset
    multiset<int> ms1;
    ms1.insert(10);
    ms1.insert(20);
    ms1.insert(20);
    ms1.insert(20);
    
    // print multiset
    for (multiset<int>::iterator it = ms1.begin(); it != ms1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    test0();
    return 0;
}
