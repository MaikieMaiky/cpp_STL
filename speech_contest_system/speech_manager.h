#ifndef __SPEECH_MANAGER_H
#define __SPEECH_MANAGER_H

#include <vector>
#include <map>
#include "speaker.h"
using namespace std;

class speech_manager
{
public:
    speech_manager() {}
    ~speech_manager() {}

    void show_menu();       // 显示菜单
    void exit_system();     // 退出系统

    void init_speech();     // 初始化比赛
    void create_speaker();  // 创建选手

    void start_speech();    // 开始比赛
    void speech_draw();     // 抽签
    void speech_contest();  // 比赛
    void show_score();      // 显示分数

    void save_record();     // 保存最终前三名记录
    void load_record();     // 加载历史记录
    void show_record();     // 显示历史记录
    void clear_record();    // 清空历史记录

public:
    vector<int> _round1_ids;        // 第一轮选手编号
    vector<int> _round2_ids;        // 第二轮选手编号
    vector<int> _victory_ids;       // 决赛选手编号

    map<int, speaker> _speakers;    // 选手编号与选手对象的映射

    int _round_index;       // 当前轮次
    bool _file_is_empty;    // 文件是否为空
};

#endif