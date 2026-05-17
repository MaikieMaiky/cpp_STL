// stack常用接口
/**
 * stack的接口比较少，一个简单的案例就可以搞定
 * 构造
 * stack<T> stk;            // 默认构造函数
 * stack(const stack &stk); // 拷贝构造函数
 * 赋值
 * stack& operator=(const stack &stk); // 重载等号操作符
 * 数据存取
 * push(elem);  // 入栈
 * pop();       // 出栈
 * top();       // 返回栈顶元素
 * 大小操作
 * empty();     // 判断栈是否为空
 * size();      // 返回栈的大小
 */
#include <iostream>
#include <stack>

using namespace std;

void test0()
{
    // 1. 构造
    stack<int> stk;

    // 2. 存入数据
    stk.push(1);
    stk.push(2);
    stk.push(3);

    // 3. 查看栈的大小
    cout << "the size of the stack is: " << stk.size() << endl;

    // 4. 取出数据
    // 4.1 判断栈是否为空 一词显示栈顶并弹出
    while (!stk.empty())
    {
        // 4.1 查看栈顶元素
        cout << "the top element is: " << stk.top() << endl;
        // 4.2 弹出栈顶元素
        stk.pop();
    }

}


int main()
{
    test0();
    return 0;
}