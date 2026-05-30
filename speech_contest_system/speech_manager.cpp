#include "speech_manager.h"
#include <iostream>
#include <fstream>
#include <map>
#include <random>
#include <algorithm>
#include <deque>
#include <numeric>

// 构造函数
speech_manager::speech_manager()
{
    load_record();
}


// 显示菜单
void speech_manager::show_menu()
{
    cout << "**************************************" << endl;
    cout << "*****   speech contest system    *****" << endl;
    cout << "*****   1. start speech contest  *****" << endl;
    cout << "*****   2. show past records     *****" << endl;
    cout << "*****   3. clear past records    *****" << endl;
    cout << "*****   0. exit                  *****" << endl;
    cout << "**************************************" << endl;
}

// 退出系统
void speech_manager::exit_system()
{
    system("cls");
    cout << "**************************************" << endl;
    cout << "******  thank you for using     ******" << endl;
    cout << "******  speech contest system   ******" << endl;
    cout << "**************************************" << endl;
    exit(0);
}


// 初始化比赛
void speech_manager::init_speech()
{
    // 清空容器
    _round1_ids.clear();
    _round2_ids.clear();
    _victory_ids.clear();
    _speakers.clear();
    // 初始化轮次
    _round_index = 1;
    // 初始化文件状态
    _file_is_empty = true;
}

// 创建选手
void speech_manager::create_speaker()
{
    // 创建12名选手
    string name_seed = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 12; i++)
    {
        string name = "speaker";
        name += name_seed[i];
        speaker sp(name);
        // 将选手放入容器中
        _speakers.insert({10000 + i, sp});
        // 将选手编号放入第一轮选手编号容器中
        _round1_ids.push_back(10000 + i);
    }
}

// 开始比赛
void speech_manager::start_speech()
{
    // 初始化比赛
    init_speech();
    // 创建选手
    create_speaker();

    _round_index = 1;
    // 第一轮抽签
    speech_draw();
    // 第一轮比赛
    speech_contest();
    // 显示第一轮晋级选手
    show_score();

    _round_index = 2;
    // 第二轮抽签
    speech_draw();
    // 第二轮比赛
    speech_contest();
    // 显示最终前三名
    show_score();

    // 保存记录
    save_record();
}

// 抽签 需区分第一轮和第二轮
void speech_manager::speech_draw()
{
    // 打印相关信息
    cout << _round_index << " round draw is starting..." << endl;
    // 顺序如下
    cout << "the order of the speakers is as follows:" << endl;

    // 第一轮抽签
    if (_round_index == 1)
    {
        shuffle(_round1_ids.begin(), _round1_ids.end(), default_random_engine());
        for (auto& id : _round1_ids)
        {
            cout << id << " ";
        }
        cout << endl;
    }
    // 第二轮抽签
    else if (_round_index == 2)
    {
        shuffle(_round2_ids.begin(), _round2_ids.end(), default_random_engine());
        for (auto& id : _round2_ids)
        {
            cout << id << " ";
        }
        cout << endl;
    }
}

// 比赛 需区分第一轮和第二轮
void speech_manager::speech_contest()
{
    // 打印相关信息
    cout << _round_index << " round contest is starting..." << endl;
    // 第一轮比赛
    if (_round_index == 1)
    {
        // 分组
        multimap<double, int, greater<double>> group1_scores;
        multimap<double, int, greater<double>> group2_scores;
        // 评分
        // 前六个选手评分 结果放进group1_scores
        for (int i = 0; i < 6; i++)
        {
            // 评分
            // 10个评委打分
            deque<double> scores;
            for (int j = 0; j < 10; j++)
            {
                double score = rand() % 401 + 600;
                score = score / 10.0;
                scores.push_back(score);
            }
            // 排序
            sort(scores.begin(), scores.end());
            // 去掉最高分和最低分
            scores.pop_front();
            scores.pop_back();
            // 取平均分
            double average_score = accumulate(scores.begin(), scores.end(), 0.0) / scores.size();
            // 分数写入选手
            _speakers.at(_round1_ids[i])._score[0] = average_score;
            // 放进group1_scores
            group1_scores.insert({average_score, _round1_ids[i]});
        }
        // 后六个选手评分 结果放进group2_scores
        for (int i = 6; i < 12; i++)
        {
            // 评分
            // 10个评委打分
            deque<double> scores;
            for (int j = 0; j < 10; j++)
            {
                double score = rand() % 401 + 600;
                score = score / 10.0;
                scores.push_back(score);
            }
            // 排序
            sort(scores.begin(), scores.end());
            // 去掉最高分和最低分
            scores.pop_front();
            scores.pop_back();
            // 取平均分
            double average_score = accumulate(scores.begin(), scores.end(), 0.0) / scores.size();
            // 分数写入选手
            _speakers.at(_round1_ids[i])._score[0] = average_score;
            // 放进group2_scores
            group2_scores.insert({average_score, _round1_ids[i]});
        }

        // 晋级 - 每组前3名晋级
        int count = 0;
        for (auto it = group1_scores.begin(); it != group1_scores.end() && count < 3; it++, count++)
        {
            if (count == 3)
            {
                break;
            }
            _round2_ids.push_back(it->second);
        }
        count = 0;
        for (auto it = group2_scores.begin(); it != group2_scores.end() && count < 3; it++, count++)
        {
            if (count == 3)
            {
                break;
            }
            _round2_ids.push_back(it->second);
        }
    }
    // 第二轮比赛
    else if (_round_index == 2)
    {
        // 分组
        multimap<double, int, greater<double>> group_scores;
        // 评分
        // 6个选手评分 结果放进group_scores
        for (int i = 0; i < 6; i++)
        {
            // 评分
            // 10个评委打分
            deque<double> scores;
            for (int j = 0; j < 10; j++)
            {
                double score = rand() % 401 + 600;
                score = score / 10.0;
                scores.push_back(score);
            }
            // 排序
            sort(scores.begin(), scores.end());
            // 去掉最高分和最低分
            scores.pop_front();
            scores.pop_back();
            // 取平均分
            double average_score = accumulate(scores.begin(), scores.end(), 0.0) / scores.size();
            // 分数写入选手
            _speakers.at(_round2_ids[i])._score[1] = average_score;
            // 放进group_scores
            group_scores.insert({average_score, _round2_ids[i]});
        }
        // 晋级 - 前3名晋级
        int count = 0;
        for (auto it = group_scores.begin(); it != group_scores.end() && count < 3; it++, count++)
        {
            if (count == 3)
            {
                break;
            }
            _victory_ids.push_back(it->second);
        }
    }
}

// 显示晋级选手 需要区分第一轮和第二轮
void speech_manager::show_score()
{
    // 显示第一轮晋级选手
    if (_round_index == 1)
    {
        cout << "the " << _round_index << " round advance speakers are as follows:" << endl;
        for (auto& id : _round2_ids)
        {
            cout << id << " - " << _speakers.at(id)._score[0] << endl;
        }
        cout << endl;
    }
    // 显示第二轮晋级选手
    else if (_round_index == 2)
    {
        cout << "the " << _round_index << " round advance speakers are as follows:" << endl;
        for (auto& id : _victory_ids)
        {
            cout << id << " " << _speakers.at(id)._score[1] << endl;
        }
        cout << endl;
    }
}


// 保存记录
void speech_manager::save_record()
{
    fstream fs;
    fs.open("speech.csv", ios::out | ios::app);
    if (!fs.is_open())
    {
        cout << "file open error" << endl;
        return;
    }
    // 写入数据
    for (auto& id : _victory_ids)
    {
        fs << id << "," << _speakers.at(id)._name << "," << _speakers.at(id)._score[1] << ",";
    }
    fs << endl;
    fs.close();

    // 更新文件状态
    if (_file_is_empty == true)
    {
        _file_is_empty = false;
    }
}

// 加载历史记录 程序驱动时调用 判断文件是否为空
void speech_manager::load_record()
{
    fstream fs;
    fs.open("speech.csv", ios::in);
    if (!fs.is_open())
    {
        cout << "file open error" << endl;
        return;
    }
    // 判断文件是否为空
    if (fs.peek() == EOF)
    {
        _file_is_empty = true;
    }
    else
    {
        _file_is_empty = false;
    }
    fs.close();
}


// 显示历史记录
void speech_manager::show_record()
{
    fstream fs;
    fs.open("speech.csv", ios::in);
    if (!fs.is_open())
    {
        cout << "file open error" << endl;
        return;
    }
    // 判断文件是否为空
    if (_file_is_empty)
    {
        cout << "no record" << endl;
        fs.close();
        return;
    }
    else
    {
        cout << "record is as follows:" << endl;
        vector<string> results;
        string line;
        while (getline(fs, line))
        {
            results.push_back(line);
        }
        fs.close();
        // 显示结果 以逗号为分隔 使用制表符代替所有逗号
        for (auto& item : results)
        {
            while (item.find(',') != string::npos)
            {
                item.replace(item.find(','), 1, "\t");
            }
            cout << item << endl;
        }
    }
}

// 清空历史记录
void speech_manager::clear_record()
{
    fstream fs;
    fs.open("speech.csv", ios::out | ios::trunc);
    if (!fs.is_open())
    {
        cout << "file open error" << endl;
        return;
    }
    fs.close();
    _file_is_empty = true;
    cout << "clear record success" << endl;
}