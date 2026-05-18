// list自定义数据排序
/**
 * bool compare(const Person& p1, const Person& p2); // 比较函数
 * 对于自定义数据类型，标准库并没有提供默认实现，需要传入回调函数，实现自定义的排序规则
 * 案例描述：将Person自定义数据类型进行排序，Person中属性有姓名，年龄，身高
 * 排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
 */
#include <iostream>
#include <list>

using namespace std;

class person
{
public:
    person(string name, int age, int height) : m_name(name), m_age(age), m_height(height) {}
    
    string m_name;
    int m_age;
    int m_height;
};

void print_list(const list<person>& l)
{
    for (list<person>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << "name: " << (*it).m_name << " age: " << (*it).m_age << " height: " << (*it).m_height << endl;
    }
    cout << "--------------------------------" << endl;
}

bool my_compare(const person &p1, const person &p2)
{
    // 先判断年龄 年龄一致则判断身高
    if (p1.m_age != p2.m_age)
    {
        // 年龄升序
        return p1.m_age < p2.m_age;
    }
    else
    {
        // 年龄降序
        return p1.m_height > p2.m_height;
    }
}

void test0()
{
    list<person> l;
    // push
    l.push_back(person("Mask", 18, 180));
    l.push_back(person("Jack", 20, 175));
    l.push_back(person("Rose", 19, 170));
    l.push_back(person("Lily", 18, 160));
    l.push_back(person("Lucy", 18, 165));
    print_list(l);
    
    // sort
    l.sort(my_compare);
    print_list(l);
}

int main()
{
    test0();
    return 0;
}