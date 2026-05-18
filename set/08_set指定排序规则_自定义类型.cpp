// set指定排序规则 - 自定义类型
/**
 * 对于自定义数据类型，set必须指定排序规则才可以插入数据
 * 如果不提供排序规则，编译器会报错，因为无法比较自定义类型
 *
 * 自定义排序规则示例：
 * class compare_person
 * {
 * public:
 *     bool operator()(const person &p1, const person &p2) const
 *     {
 *         return p1.m_age > p2.m_age; // 按年龄降序
 *     }
 * };
 *
 * set<person, compare_person> st; // 对自定义数据类型指定排序规则
 */
#include <iostream>
#include <set>

using namespace std;

// 自定义类型
class person
{
public:
    person(string name, int age) : name_(name), age_(age) {}

    string name_;
    int age_;
};

// 仿函数
class compare_person
{
public:
    bool operator()(const person &p1, const person &p2) const
    {
        return p1.age_ > p2.age_;  // 年龄降序
    }
};

void test0()
{
    set<person, compare_person> s1;
    s1.insert(person("GG bond", 12));
    s1.insert(person("Mask",    50));
    s1.insert(person("Lei Jun", 45));

    // print
    for (set<person, compare_person>::const_iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << (*it).name_ << " " << (*it).age_ << endl;
    }
}

int main()
{
    test0();
    return 0;
}
