# 演讲比赛系统
## 比赛规则
- 学校举行一场演讲比赛，共有**12个人参加**。**比赛共两轮**，第一轮为淘汰赛，第二轮为决赛。
- 每名选手都有对应的**编号**，如10001~10012
- 比赛方式：**分组比赛，每组6个人**；
- 第一轮分为两个小组，整体按照选手编号进行**抽签**后顺序演讲。
- 十个评委分别给每名选手**打分**，去除最高分和最低分，求的平均分为本轮选手的成绩
- 当小组演讲完后，淘汰组内排名最后的三个选手，**前三名晋级**，进入下一轮的比赛。
- 第二轮为决赛，**前三名胜出**
- 每轮比赛过后需要**显示晋级选手的信息**

## 程序功能
- 开始演讲比赛：完成整届比赛的流程，每个比赛阶段需要给用户一个提示，用户按任意键后继续下一个阶段
- 查看往届记录：查看之前比赛前三名结果，每次比赛都会记录到文件中，文件用.csv后缀名保存
- 清空比赛记录：将文件中数据清空
- 退出比赛程序：可以退出当前程序


下面这套设计非常适合你这个 C++ 小实验：既能练到**类、容器、排序、随机数、文件读写、菜单系统**，又不会复杂到变成“代码迷宫”。整体可以理解为：**选手数据交给 `Speaker`，比赛流程交给 `SpeechManager`**。🎤

---

# 一、项目整体结构

建议分成这几个文件：

```cpp
main.cpp
speaker.h
speechManager.h
speechManager.cpp
speech.csv
```

其中：

| 文件                  | 作用               |
| ------------------- | ---------------- |
| `main.cpp`          | 程序入口，显示菜单，接收用户选择 |
| `speaker.h`         | 定义选手类            |
| `speechManager.h`   | 定义比赛管理类          |
| `speechManager.cpp` | 实现比赛流程           |
| `speech.csv`        | 保存往届前三名记录        |

---

# 二、核心类设计

## 1. 选手类：`Speaker`

每个选手需要保存：

* 姓名
* 两轮比赛成绩

```cpp
class Speaker
{
public:
    string m_Name;
    double m_Score[2];
};
```

为什么用数组 `m_Score[2]`？

因为比赛只有两轮：

```cpp
m_Score[0]  // 第一轮成绩
m_Score[1]  // 第二轮成绩
```

这样后面写比赛逻辑时会很舒服，不需要额外创建两个变量。

---

## 2. 比赛管理类：`SpeechManager`

这个类负责整个系统，相当于“比赛总导演”。
它应该管理：

* 选手创建
* 抽签
* 比赛
* 晋级
* 显示结果
* 保存记录
* 读取记录
* 清空记录
* 菜单交互

推荐这样设计：

```cpp
class SpeechManager
{
public:
    SpeechManager();

    void showMenu();        // 显示菜单
    void exitSystem();      // 退出系统

    void initSpeech();      // 初始化比赛数据
    void createSpeaker();   // 创建12名选手

    void startSpeech();     // 开始比赛总流程
    void speechDraw();      // 抽签
    void speechContest();   // 比赛
    void showScore();       // 显示晋级结果

    void saveRecord();      // 保存记录
    void loadRecord();      // 加载记录
    void showRecord();      // 查看往届记录
    void clearRecord();     // 清空记录

public:
    vector<int> m_v1;        // 第一轮比赛选手编号
    vector<int> m_v2;        // 第二轮比赛选手编号
    vector<int> m_vVictory;  // 最终前三名选手编号

    map<int, Speaker> m_Speaker; // 编号与选手对象的映射

    int m_Index;             // 当前比赛届数
    bool fileIsEmpty;        // 文件是否为空
};
```

---

# 三、容器选用设计

这是这个项目最关键的部分，容器选对了，代码就会很顺。

## 1. `map<int, Speaker> m_Speaker`

用来保存所有选手信息。

```cpp
map<int, Speaker> m_Speaker;
```

结构大概是：

```cpp
10001 -> 选手A
10002 -> 选手B
10003 -> 选手C
...
```

为什么用 `map`？

因为选手编号是唯一的，而且你经常会通过编号查找选手：

```cpp
m_Speaker[10001].m_Name;
m_Speaker[10001].m_Score[0];
```

这比用普通数组更清晰。

---

## 2. `vector<int> m_v1`

保存第一轮所有选手编号。

```cpp
m_v1 = {10001, 10002, ..., 10012};
```

第一轮抽签，其实就是打乱这个 `vector`。

```cpp
shuffle(m_v1.begin(), m_v1.end(), ...);
```

---

## 3. `vector<int> m_v2`

保存第二轮晋级选手编号。

第一轮结束后，每组前三名晋级。

所以 `m_v2` 最后应该有 6 个编号。

```cpp
m_v2 = {晋级选手1, 晋级选手2, ..., 晋级选手6};
```

---

## 4. `vector<int> m_vVictory`

保存最终前三名。

第二轮结束后，前三名进入这里：

```cpp
m_vVictory = {冠军编号, 亚军编号, 季军编号};
```

---

## 5. `deque<double>` 临时保存评委分数

每个选手有 10 个评委打分，需要：

1. 排序
2. 去掉最高分
3. 去掉最低分
4. 求平均分

推荐用：

```cpp
deque<double> d;
```

因为 `deque` 方便头尾删除：

```cpp
d.pop_front(); // 去掉最低分
d.pop_back();  // 去掉最高分
```

当然，用 `vector<double>` 也可以，只是删除首元素没有 `deque` 自然。

---

# 四、比赛流程设计

整个比赛流程可以这样走：

```text
开始比赛
  ↓
创建12名选手
  ↓
第一轮抽签
  ↓
第一轮比赛
  ↓
显示第一轮晋级选手
  ↓
第二轮抽签
  ↓
第二轮比赛
  ↓
显示最终前三名
  ↓
保存比赛记录
  ↓
比赛结束
```

也就是 `startSpeech()` 负责串起来：

```cpp
void SpeechManager::startSpeech()
{
    // 第一轮
    speechDraw();
    speechContest();
    showScore();

    // 第二轮
    speechDraw();
    speechContest();
    showScore();

    // 保存结果
    saveRecord();

    // 重置比赛状态
    initSpeech();
    createSpeaker();
}
```

不过这里有一个设计重点：
你需要用一个变量判断当前是第几轮，比如 `m_Index`。

```cpp
m_Index = 1; // 第一轮
m_Index = 2; // 第二轮
```

---

# 五、每轮比赛逻辑设计

## 第一轮

第一轮有 12 人，分成 2 组，每组 6 人。

```text
第一组：6人，取前三
第二组：6人，取前三
```

第一轮结束后：

```text
晋级人数：6人
淘汰人数：6人
```

## 第二轮

第二轮有 6 人，还是一组比赛。

```text
6人比赛，取前三
```

第二轮结束后：

```text
冠军
亚军
季军
```

---

# 六、比赛评分设计

每个选手评分流程：

```text
生成10个评委分数
  ↓
排序
  ↓
去掉最低分
  ↓
去掉最高分
  ↓
求平均分
  ↓
保存到选手成绩中
```

你可以先用随机分数模拟：

```cpp
double score = rand() % 401 + 600;
score = score / 10.0;
```

这样可以生成：

```text
60.0 ~ 100.0
```

评分设计示意：

```cpp
deque<double> scores;

for (int i = 0; i < 10; i++)
{
    double score = 随机生成;
    scores.push_back(score);
}

sort(scores.begin(), scores.end());

scores.pop_front();
scores.pop_back();

double sum = 0;
for (double s : scores)
{
    sum += s;
}

double avg = sum / scores.size();
```

然后根据当前轮次保存：

```cpp
m_Speaker[选手编号].m_Score[m_Index - 1] = avg;
```

---

# 七、小组晋级逻辑设计

这一部分建议使用一个临时容器保存当前小组选手成绩。

可以用：

```cpp
multimap<double, int, greater<double>> groupScore;
```

含义是：

```cpp
成绩 -> 选手编号
```

为什么用 `multimap`？

因为可能有选手同分，所以用 `multimap` 比 `map` 更安全。

为什么加 `greater<double>`？

因为成绩要从高到低排序。

```cpp
multimap<double, int, greater<double>> groupScore;
```

小组比赛结束后，取前三名：

```cpp
int count = 0;

for (auto it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
{
    if (m_Index == 1)
    {
        m_v2.push_back(it->second);
    }
    else
    {
        m_vVictory.push_back(it->second);
    }
}
```

---

# 八、抽签功能设计

抽签就是打乱选手编号顺序。

第一轮打乱：

```cpp
shuffle(m_v1.begin(), m_v1.end(), ...);
```

第二轮打乱：

```cpp
shuffle(m_v2.begin(), m_v2.end(), ...);
```

抽签后显示顺序：

```text
第1位演讲：10003 选手C
第2位演讲：10008 选手H
...
```

这样用户能看到比赛顺序。

---

# 九、文件保存设计

建议使用 `speech.csv` 保存每届比赛前三名。

## 推荐 CSV 格式

一届比赛一行：

```csv
届数,冠军编号,冠军姓名,冠军分数,亚军编号,亚军姓名,亚军分数,季军编号,季军姓名,季军分数
```

示例：

```csv
1,10008,选手H,92.35,10003,选手C,90.12,10011,选手K,88.65
2,10001,选手A,95.20,10007,选手G,91.45,10010,选手J,89.80
```

这样查看往届记录时很方便。

---

# 十、菜单功能设计

主菜单可以这样：

```text
******************************
******  欢迎参加演讲比赛  ******
******  1. 开始演讲比赛  ******
******  2. 查看往届记录  ******
******  3. 清空比赛记录  ******
******  0. 退出比赛程序  ******
******************************
```

对应逻辑：

```cpp
int choice;
cin >> choice;

switch (choice)
{
case 1:
    startSpeech();
    break;
case 2:
    showRecord();
    break;
case 3:
    clearRecord();
    break;
case 0:
    exitSystem();
    break;
default:
    cout << "输入有误，请重新输入" << endl;
    break;
}
```

---

# 十一、每个函数的职责

## `initSpeech()`

初始化所有容器。

```text
清空第一轮容器
清空第二轮容器
清空冠军容器
清空选手map
初始化比赛轮次
```

注意：每次重新开始比赛前都应该调用它。

---

## `createSpeaker()`

创建 12 名选手。

编号：

```text
10001 ~ 10012
```

姓名可以先简单写：

```text
选手A
选手B
选手C
...
```

创建后：

```cpp
m_Speaker.insert(make_pair(id, speaker));
m_v1.push_back(id);
```

也就是：

```text
map保存选手详细信息
vector保存比赛顺序
```

---

## `speechDraw()`

根据当前轮次进行抽签。

```text
如果是第一轮，打乱 m_v1
如果是第二轮，打乱 m_v2
```

---

## `speechContest()`

核心比赛函数。

职责：

```text
根据当前轮次选择比赛容器
每6个人为一组
每个选手产生10个分数
去掉最高最低分
求平均分
保存成绩
每组取前三名
```

这是整个项目最难的函数。

你可以重点把它拆成三层：

```text
第1层：判断当前是第几轮
第2层：按照每6人为一组比赛
第3层：给每个选手打分并排序晋级
```

---

## `showScore()`

显示每轮晋级选手。

第一轮显示：

```text
第一轮晋级选手：
编号：10003 姓名：选手C 成绩：88.5
编号：10007 姓名：选手G 成绩：91.2
...
```

第二轮显示：

```text
本届比赛前三名：
冠军：10008 选手H 成绩：95.6
亚军：10003 选手C 成绩：93.1
季军：10011 选手K 成绩：90.4
```

---

## `saveRecord()`

把最终前三名写入文件。

打开方式建议用追加：

```cpp
ofstream ofs("speech.csv", ios::out | ios::app);
```

因为每次比赛都要保留历史记录。

---

## `loadRecord()`

程序启动时读取文件，判断是否有历史记录。

可以设置：

```cpp
fileIsEmpty = true;
```

如果文件为空，就提示：

```text
文件为空，暂无比赛记录
```

---

## `showRecord()`

读取 `speech.csv`，显示所有往届比赛前三名。

显示格式可以设计成：

```text
第1届比赛结果：
冠军：10008 选手H 分数：92.35
亚军：10003 选手C 分数：90.12
季军：10011 选手K 分数：88.65
```

---

## `clearRecord()`

清空文件。

```cpp
ofstream ofs("speech.csv", ios::trunc);
ofs.close();
```

同时更新状态：

```cpp
fileIsEmpty = true;
m_Index = 1;
```

---

# 十二、推荐完整流程图

```text
程序启动
  ↓
创建 SpeechManager 对象
  ↓
加载历史记录
  ↓
显示菜单
  ↓
用户选择功能
  ↓
1. 开始比赛
     ↓
   初始化选手
     ↓
   第一轮抽签
     ↓
   第一轮比赛
     ↓
   显示晋级6人
     ↓
   第二轮抽签
     ↓
   第二轮比赛
     ↓
   显示前三名
     ↓
   保存记录

2. 查看记录
     ↓
   读取 speech.csv
     ↓
   显示往届前三名

3. 清空记录
     ↓
   清空 speech.csv

0. 退出程序
```

---

# 十三、你这个项目主要练到的 C++ 知识

| 知识点        | 在项目中的体现                   |
| ---------- | ------------------------- |
| 类和对象       | `Speaker`、`SpeechManager` |
| 构造函数       | 初始化比赛管理系统                 |
| `vector`   | 保存比赛选手编号                  |
| `map`      | 编号映射选手信息                  |
| `deque`    | 存放评委分数，方便去头尾              |
| `multimap` | 按成绩排序并允许同分                |
| `sort`     | 排序评委分数                    |
| `shuffle`  | 抽签打乱顺序                    |
| 文件读写       | 保存和查看历史记录                 |
| 菜单系统       | 控制程序流程                    |
| 函数封装       | 每个功能独立成函数                 |

---

# 十四、推荐你先按这个顺序写

不要一上来就写完整项目，不然很容易变成代码毛线球 🧶。

建议顺序：

```text
1. 先写 Speaker 类
2. 再写 SpeechManager 类框架
3. 写菜单 showMenu()
4. 写 initSpeech()
5. 写 createSpeaker()
6. 写 speechDraw()
7. 写 speechContest()
8. 写 showScore()
9. 写 saveRecord()
10. 写 showRecord()
11. 写 clearRecord()
```

最难的是：

```text
speechContest()
```

所以你可以先把文件读写放后面，先保证比赛流程能完整跑通。
