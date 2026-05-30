# 演讲比赛系统
[返回主页](../README.md)


本目录是一个 C++ 综合练习项目，用来模拟学校演讲比赛的完整流程。项目适合练习类、对象、STL 容器、排序、随机数、文件读写和菜单交互等内容。

整体思路可以概括为：`speaker` 负责保存选手数据，`speech_manager` 负责组织比赛流程。

## 比赛规则

- 学校举办一场演讲比赛，共有 12 名选手参加。
- 比赛分为两轮：第一轮为淘汰赛，第二轮为决赛。
- 每名选手都有唯一编号，例如 `10001` 到 `10012`。
- 第一轮分为 2 个小组，每组 6 人。每组前 3 名晋级。
- 第二轮由 6 名晋级选手参赛，最终取前 3 名。
- 每名选手由 10 位评委打分，去掉最高分和最低分后，计算平均分作为本轮成绩。
- 每轮比赛结束后，需要显示晋级选手或最终前三名的信息。

## 程序功能

- 开始演讲比赛：完成抽签、评分、晋级、决赛和结果保存等流程。
- 查看往届记录：读取 `speech.csv` 中保存的历史前三名结果。
- 清空比赛记录：清空 `speech.csv` 中的历史数据。
- 退出比赛程序：结束当前程序。

## 项目文件

建议将项目拆分为以下文件：

```text
main.cpp
speaker.h
speech_manager.h
speech_manager.cpp
speech.csv
```

| 文件 | 作用 |
|------|------|
| `main.cpp` | 程序入口，显示菜单并接收用户选择 |
| `speaker.h` | 定义选手类 `speaker` |
| `speech_manager.h` | 定义比赛管理类 `speech_manager` |
| `speech_manager.cpp` | 实现比赛流程、文件读写和菜单逻辑 |
| `speech.csv` | 保存往届比赛前三名记录 |

## 核心类设计

### `speaker`

`speaker` 用来保存单个选手的姓名和两轮比赛成绩：

```cpp
class speaker
{
public:
    string _name;
    double _score[2];
};
```

`_score[0]` 表示第一轮成绩，`_score[1]` 表示第二轮成绩。因为比赛固定为两轮，使用长度为 2 的数组就能清楚表达数据含义。

### `speech_manager`

`speech_manager` 负责管理整个系统，包括选手创建、抽签、比赛、晋级、结果展示、记录保存和记录读取。

```cpp
class speech_manager
{
public:
    speech_manager();

    void show_menu();
    void exit_system();

    void init_speech();
    void create_speaker();

    void start_speech();
    void speech_draw();
    void speech_contest();
    void show_score();

    void save_record();
    void load_record();
    void show_record();
    void clear_record();

public:
    vector<int> _round1_ids;
    vector<int> _round2_ids;
    vector<int> _victory_ids;

    map<int, speaker> _speakers;

    int _round_index;
    bool _file_is_empty;
};
```

## 容器选型

### `map<int, speaker> _speakers`

`_speakers` 保存编号与选手对象之间的映射：

```cpp
map<int, speaker> _speakers;
```

结构可以理解为：

```text
10001 -> 选手 A
10002 -> 选手 B
10003 -> 选手 C
...
```

使用 `map` 的原因是选手编号唯一，并且程序经常需要通过编号查找选手信息：

```cpp
_speakers[10001]._name;
_speakers[10001]._score[0];
```

### `vector<int> _round1_ids`

`_round1_ids` 保存第一轮所有选手编号：

```cpp
_round1_ids = {10001, 10002, 10003, 10004, 10005, 10006,
               10007, 10008, 10009, 10010, 10011, 10012};
```

第一轮抽签就是打乱这个 `vector`：

```cpp
shuffle(_round1_ids.begin(), _round1_ids.end(), random_engine);
```

### `vector<int> _round2_ids`

`_round2_ids` 保存第一轮晋级选手编号。第一轮结束后，每组前 3 名晋级，所以该容器最终会有 6 个编号。

```cpp
_round2_ids = {晋级选手1, 晋级选手2, 晋级选手3,
               晋级选手4, 晋级选手5, 晋级选手6};
```

### `vector<int> _victory_ids`

`_victory_ids` 保存最终前三名选手编号：

```cpp
_victory_ids = {冠军编号, 亚军编号, 季军编号};
```

### `deque<double> scores`

每名选手有 10 个评委分数，需要排序后去掉最高分和最低分。`deque` 支持方便地从头尾删除元素：

```cpp
deque<double> scores;

scores.pop_front(); // 去掉最低分
scores.pop_back();  // 去掉最高分
```

### `multimap<double, int, greater<double>> group_scores`

小组比赛结束后，可以用 `multimap` 按成绩保存选手编号：

```cpp
multimap<double, int, greater<double>> group_scores;
```

这里使用 `multimap` 是为了允许选手同分，使用 `greater<double>` 是为了让成绩从高到低排序。

## 比赛流程

完整比赛流程如下：

```text
开始比赛
  -> 创建 12 名选手
  -> 第一轮抽签
  -> 第一轮比赛
  -> 显示第一轮晋级选手
  -> 第二轮抽签
  -> 第二轮比赛
  -> 显示最终前三名
  -> 保存比赛记录
  -> 比赛结束
```

`start_speech()` 可以负责串联整个流程：

```cpp
void speech_manager::start_speech()
{
    _round_index = 1;
    speech_draw();
    speech_contest();
    show_score();

    _round_index = 2;
    speech_draw();
    speech_contest();
    show_score();

    save_record();

    init_speech();
    create_speaker();
}
```

## 每轮比赛逻辑

第一轮有 12 名选手，分为 2 个小组，每组 6 人，每组取前 3 名晋级。第二轮有 6 名选手，作为一个小组比赛，最终取前 3 名。

```text
第一轮：12 人 -> 2 组 -> 每组前 3 名 -> 晋级 6 人
第二轮：6 人 -> 1 组 -> 前 3 名 -> 冠军、亚军、季军
```

## 评分逻辑

每名选手的评分流程如下：

```text
生成 10 个评委分数
  -> 排序
  -> 去掉最低分
  -> 去掉最高分
  -> 计算平均分
  -> 保存到选手成绩中
```

可以先用随机数模拟评委打分：

```cpp
double score = rand() % 401 + 600;
score = score / 10.0;
```

这样可以生成 `60.0` 到 `100.0` 之间的分数。

评分示例：

```cpp
deque<double> scores;

for (int i = 0; i < 10; i++)
{
    double score = rand() % 401 + 600;
    score = score / 10.0;
    scores.push_back(score);
}

sort(scores.begin(), scores.end());

scores.pop_front();
scores.pop_back();

double sum = 0;
for (double score : scores)
{
    sum += score;
}

double average_score = sum / scores.size();
_speakers[player_id]._score[_round_index - 1] = average_score;
```

## 晋级逻辑

小组比赛时，用 `group_scores` 临时保存当前小组选手的成绩：

```cpp
multimap<double, int, greater<double>> group_scores;
```

小组比赛结束后，取前 3 名：

```cpp
int count = 0;

for (auto it = group_scores.begin(); it != group_scores.end() && count < 3; it++, count++)
{
    if (_round_index == 1)
    {
        _round2_ids.push_back(it->second);
    }
    else
    {
        _victory_ids.push_back(it->second);
    }
}
```

## 抽签逻辑

抽签本质上就是打乱当前轮次的选手编号顺序。

第一轮：

```cpp
shuffle(_round1_ids.begin(), _round1_ids.end(), random_engine);
```

第二轮：

```cpp
shuffle(_round2_ids.begin(), _round2_ids.end(), random_engine);
```

抽签后可以显示演讲顺序：

```text
第 1 位演讲：10003 选手 C
第 2 位演讲：10008 选手 H
...
```

## 文件保存设计

建议使用 `speech.csv` 保存每届比赛的前三名。一届比赛保存一行：

```csv
冠军编号,冠军姓名,冠军分数,亚军编号,亚军姓名,亚军分数,季军编号,季军姓名,季军分数
```

示例：

```csv
10008,选手H,92.35,10003,选手C,90.12,10011,选手K,88.65
10001,选手A,95.20,10007,选手G,91.45,10010,选手J,89.80
```

保存时使用追加方式，避免覆盖历史记录：

```cpp
ofstream output_file("speech.csv", ios::out | ios::app);
```

清空记录时使用截断方式：

```cpp
ofstream output_file("speech.csv", ios::trunc);
output_file.close();

_file_is_empty = true;
_round_index = 1;
```

## 菜单设计

主菜单可以设计为：

```text
******************************
******  欢迎参加演讲比赛  ******
******  1. 开始演讲比赛  ******
******  2. 查看往届记录  ******
******  3. 清空比赛记录  ******
******  0. 退出比赛程序  ******
******************************
```

对应的选择逻辑：

```cpp
int choice = 0;
cin >> choice;

switch (choice)
{
case 1:
    start_speech();
    break;
case 2:
    show_record();
    break;
case 3:
    clear_record();
    break;
case 0:
    exit_system();
    break;
default:
    cout << "输入有误，请重新输入" << endl;
    break;
}
```

## 主要函数职责

| 函数 | 职责 |
|------|------|
| `init_speech()` | 清空比赛容器，初始化比赛轮次和状态 |
| `create_speaker()` | 创建 12 名选手，并写入 `_speakers` 与 `_round1_ids` |
| `speech_draw()` | 根据当前轮次打乱 `_round1_ids` 或 `_round2_ids` |
| `speech_contest()` | 完成当前轮次的分组、评分、排序和晋级 |
| `show_score()` | 显示第一轮晋级选手或最终前三名 |
| `save_record()` | 将最终前三名追加写入 `speech.csv` |
| `load_record()` | 程序启动时读取历史记录，并判断文件是否为空 |
| `show_record()` | 显示往届比赛前三名 |
| `clear_record()` | 清空 `speech.csv`，并更新文件状态 |

## 推荐实现顺序

建议按以下顺序实现，先让比赛主流程跑通，再补充文件读写：

```text
1. 编写 speaker 类
2. 编写 speech_manager 类框架
3. 实现 show_menu()
4. 实现 init_speech()
5. 实现 create_speaker()
6. 实现 speech_draw()
7. 实现 speech_contest()
8. 实现 show_score()
9. 实现 save_record()
10. 实现 show_record()
11. 实现 clear_record()
```

其中 `speech_contest()` 是核心函数，建议拆成三步理解：判断当前轮次、按小组比赛、按成绩筛选晋级选手。

## 涉及的 C++ 知识点

| 知识点 | 在项目中的体现 |
|--------|----------------|
| 类和对象 | `speaker`、`speech_manager` |
| 构造函数 | 初始化比赛管理系统 |
| `vector` | 保存比赛选手编号 |
| `map` | 根据编号映射选手信息 |
| `deque` | 保存评委分数，便于删除头尾元素 |
| `multimap` | 按成绩排序，并允许同分 |
| `sort` | 对评委分数排序 |
| `shuffle` | 模拟抽签，打乱选手顺序 |
| 文件读写 | 保存和查看历史比赛记录 |
| 菜单系统 | 控制程序流程 |
| 函数封装 | 将不同功能拆分到独立函数中 |
