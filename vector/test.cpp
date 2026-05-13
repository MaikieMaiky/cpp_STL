// vector的简单使用

#include <iostream>
#include <vector>

using namespace std;

// 内置类型
void test0()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

class person
{
public:
    person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    string name;
    int age;
};

// 自定义类型
void test1()
{
    vector<person> v;
    person p1("Monkey King", 1000);
    person p2("Sun Wukong", 1000);
    person p3("Shu Guang", 1000);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "name: " << (*it).name << " age: " << (*it).age << endl;
    }
}

// 容器套容器
void test2()
{
    vector<vector<int>> v;
    vector<int> vv1;
    vector<int> vv2;
    vector<int> vv3;
    for (int i = 0; i < 4; i++)
    {
        vv1.push_back(i);
        vv2.push_back(i);
        vv3.push_back(i);
    }

    v.push_back(vv1);
    v.push_back(vv2);
    v.push_back(vv3);

    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}

int main()
{
    test2();
    return 0;
}