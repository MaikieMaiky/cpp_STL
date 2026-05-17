// queue的常用接口
/**
 * 构造
 * queue<T> que;            // 默认构造函数
 * queue(const queue &que); // 拷贝构造函数
 * 赋值
 * queue& operator=(const queue &que); // 重载等号操作符
 * 数据存取
 * push(elem);  // 入队
 * pop();       // 出队
 * front();     // 返回队首元素
 * back();      // 返回队尾元素
 * 大小操作
 * empty();     // 判断队列是否为空
 * size();      // 返回队列的大小
 */
#include <iostream>
#include <queue>

using namespace std;

class person
{
public:
    person(string name, int age) : m_name(name), m_age(age) {}

    string m_name;
    int m_age;
};

void test0()
{
    // 1. 构造
    queue<person> que;

    // 2. 入队
    que.push(person("master", 23));
    que.push(person("monkey bro", 1000));
    que.push(person("pig bro", 2000));
    que.push(person("sha bro", 4000));

    // 3. 查看队列的大小
    cout << "the size of the queue is: " << que.size() << endl;

    // 4. 取出数据
    // 4.1 判断队列是否为空 一次显示队首和队尾并弹出
    while (!que.empty())
    {
        // 4.1 查看队首元素
        cout << "the front element is: " << que.front().m_name << " " << que.front().m_age << endl;
        // 4.2 查看队尾元素
        cout << "the back element is: " << que.back().m_name << " " << que.back().m_age << endl;
        // 4.3 弹出队首元素
        que.pop();
    }

    // 5. 查看队列大小
    cout << "the size of the queue is: " << que.size() << endl;
}

int main()
{
    test0();
    return 0;
}