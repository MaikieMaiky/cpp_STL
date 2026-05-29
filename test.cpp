// 函数对象模板 + 泛型算法
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;


void print_vector(int val)
{
    cout << val << " ";
}

class greater_than_5
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};


void test0()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);

    for_each(v.begin(), v.end(), print_vector);
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), print_vector);
    cout << endl;

    vector<int> v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), negate<int>());
    for_each(v2.begin(), v2.end(), print_vector);
    cout << endl;

    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "sum = " << sum << endl;

    replace_if(v.begin(), v.end(), greater_than_5(), 100);
    for_each(v.begin(), v.end(), print_vector);
    cout << endl;

    int count = count_if(v.begin(), v.end(), greater_than_5());
    cout << "count = " << count << endl;
}

int main()
{
    test0();
    return 0;
}