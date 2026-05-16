// 评委打分案例
/**
 * 有5名选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除最低分，取平均分，显示各个选手得分
 * 涉及到了vector容器、deque容器、排序算法
 * 步骤:
 * 1. 创建5名选手
 * 2. 10位评委打分，存入deque
 * 3. 排序deque，删除首尾来去除最高分和最低分
 * 4. 取平均分
 * 5. 显示各个选手得分
 */

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>

using namespace std;

class player
{
public:
    player(string name) : name(name), score(0) {}

    string name;
    int score;
};

// 创建5名选手
void create_player(vector<player>& v)
{
    for (int i = 0; i < 5; i++)
    {
        string name = "player";
        name += 'A' + i;
        player p(name);
        v.push_back(p);
    }
}

// 打分
void set_score(vector<player>& v)
{
    // 取出每一个选手
    for (vector<player>::iterator it = v.begin(); it != v.end(); it++)
    {
        // 10个评委打分并放入deque
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            // 分数在40到100之间
            int score = rand() % 60 + 41;
            d.push_back(score);
        }

        // 排序
        sort(d.begin(), d.end());
        // 删除头尾（最高分和最低分）
        d.pop_front();
        d.pop_back();

        // 取平均分
        int sum = 0;
        for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
        {
            sum += *it;
        }
        sum /= d.size();

        (*it).score = sum;
    }
}

// 显示选手和其得分
void show_player(vector<player>& v)
{
    for (vector<player>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it).name << " score: " << (*it).score << endl;
    }
}


void test0()
{
    // 设置随机数种子
    srand((unsigned int)time(NULL));

    // 1. 创建5名选手
    vector<player> v;
    create_player(v);

    // 2. 打分
    set_score(v);

    // 3. 显示得分
    show_player(v);
}

int main()
{
    test0();
    return 0;
}