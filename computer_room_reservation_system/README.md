# 机房预约系统

[返回主页](../README.md)

本目录用于完成一个 C++ 综合练习项目：机房预约系统。项目源码文件和数据文件已经创建为空文件，后续可以按照本文档逐步实现。

项目适合练习：

- 类和对象
- 继承与多态
- `vector`、`map`
- 嵌套 `map`
- CSV 文件读写
- 菜单交互
- 登录验证
- 预约状态管理

## 一、项目需求

系统包含三类身份：

| 身份 | 主要职责 |
|------|----------|
| 学生代表 | 申请预约、查看预约、取消预约 |
| 教师 | 查看预约、审核预约 |
| 管理员 | 添加账号、查看账号、查看机房、清空预约 |

系统包含三个机房：

| 机房编号 | 最大容量 |
|----------|----------|
| 1 | 20 人 |
| 2 | 50 人 |
| 3 | 100 人 |

预约规则：

- 学生可以预约未来一周内周一到周五的机房。
- 每次预约需要选择日期、时段和机房。
- 时段分为上午和下午。
- 教师可以通过或拒绝审核中的预约。
- 学生可以取消审核中或预约成功的记录。
- 管理员每周清空全部预约记录。

## 二、目录结构

```text
computer_room_reservation_system/
├── main.cpp
├── identity.h
├── student.h
├── student.cpp
├── teacher.h
├── teacher.cpp
├── administrator.h
├── administrator.cpp
├── machine_room.h
├── reservation.h
├── reservation_file.h
├── reservation_file.cpp
├── computer_room_reservation_system.h
├── computer_room_reservation_system.cpp
├── data/
│   ├── student.csv
│   ├── teacher.csv
│   ├── admin.csv
│   ├── machine_room.csv
│   └── reservation.csv
└── README.md
```

## 三、命名约定

本项目采用 Google C++ 风格：

| 类型 | 示例 |
|------|------|
| 类名、结构体名 | `Student`、`MachineRoom` |
| 函数名 | `ShowMenu()`、`ApplyReservation()` |
| 普通变量 | `student_id`、`room_id` |
| 成员变量 | `student_id_`、`reservations_` |
| 常量 | `kStudentFile`、`kMinWeekday` |
| 枚举值 | `kMorning`、`kApproved` |

## 四、文件职责

| 文件 | 职责 |
|------|------|
| `main.cpp` | 程序入口，创建系统对象并调用 `Run()` |
| `identity.h` | 定义身份基类 `Identity` |
| `student.h`、`student.cpp` | 定义并实现学生类 `Student` |
| `teacher.h`、`teacher.cpp` | 定义并实现教师类 `Teacher` |
| `administrator.h`、`administrator.cpp` | 定义并实现管理员类 `Administrator` |
| `machine_room.h` | 定义机房结构体 `MachineRoom` |
| `reservation.h` | 定义预约信息和预约集合的类型别名 |
| `reservation_file.h`、`reservation_file.cpp` | 封装预约文件的读取、保存和清空操作 |
| `computer_room_reservation_system.h`、`computer_room_reservation_system.cpp` | 负责主菜单、登录验证和系统主流程 |
| `data/*.csv` | 保存账号、机房和预约数据 |

## 五、核心数据结构

### `Identity`

三类身份都具有姓名和密码，并且都需要显示自己的菜单。可以使用抽象基类统一表示：

```cpp
class Identity {
 public:
  virtual ~Identity() = default;
  virtual void ShowMenu() = 0;

 protected:
  std::string name_;
  std::string password_;
};
```

### `Student`

学生需要保存：

```text
学号
姓名
密码
```

学生功能：

```text
1. 申请预约
2. 查看自身预约
3. 查看所有预约
4. 取消预约
5. 注销登录
```

### `Teacher`

教师需要保存：

```text
职工号
姓名
密码
```

教师功能：

```text
1. 查看所有预约
2. 审核预约
3. 注销登录
```

### `Administrator`

管理员需要保存：

```text
管理员姓名
密码
```

管理员功能：

```text
1. 添加账号
2. 查看账号
3. 查看机房
4. 清空预约
5. 注销登录
```

### `MachineRoom`

```cpp
struct MachineRoom {
  int room_id;
  int capacity;
};
```

### `Reservation`

一条预约使用 `std::map<std::string, std::string>` 保存。键表示字段名称，值统一使用字符串保存：

```cpp
using Reservation = std::map<std::string, std::string>;
```

一条预约示例：

```cpp
Reservation reservation{
    {"weekday", "1"},
    {"time_slot", "1"},
    {"student_id", "1001"},
    {"student_name", "张三"},
    {"room_id", "1"},
    {"status", "1"},
};
```

全部预约使用第二层 `map` 保存。外层键为预约编号，外层值为对应的预约信息：

```cpp
using Reservations = std::map<int, Reservation>;
```

示例：

```cpp
Reservations reservations;
reservations[1] = reservation;
```

逻辑结构：

```text
预约编号
  -> 字段名称
    -> 字段值

1
  -> "weekday"      -> "1"
  -> "time_slot"    -> "1"
  -> "student_id"   -> "1001"
  -> "student_name" -> "张三"
  -> "room_id"      -> "1"
  -> "status"       -> "1"
```

预约编号已经作为外层 `map` 的键保存，因此内层 `map` 不需要重复保存 `reservation_id`。

状态流转：

```text
申请预约 -> 审核中
审核中 -> 预约成功
审核中 -> 审核未通过
审核中 -> 已取消
预约成功 -> 已取消
```

修改预约状态时，只需要更新对应字段：

```cpp
reservations[reservation_id]["status"] = "0";
```

注意：`operator[]` 会在键不存在时自动创建数据。根据用户输入查找预约编号时，建议先使用 `find()` 判断预约是否存在，再修改状态。

### `ReservationFile`

`ReservationFile` 负责管理全部预约。可以将两层 `map` 作为成员变量：

```cpp
class ReservationFile {
 public:
  void LoadReservations();
  void SaveReservations() const;
  void ClearReservations();

  int GetNextReservationId() const;

  Reservations& reservations();
  const Reservations& reservations() const;

 private:
  Reservations reservations_;
};
```

其中：

| 成员或函数 | 职责 |
|------------|------|
| `reservations_` | 保存全部预约，键为预约编号 |
| `LoadReservations()` | 从 CSV 文件读取预约并填充两层 `map` |
| `SaveReservations()` | 遍历两层 `map` 并覆盖写入 CSV 文件 |
| `ClearReservations()` | 清空 `reservations_` 和 CSV 文件 |
| `GetNextReservationId()` | 返回下一个可用的预约编号 |

## 六、容器选择

| 数据 | 推荐容器 | 原因 |
|------|----------|------|
| 学生账号 | `std::vector<Student>` | 账号数量不大，登录和查重时遍历即可 |
| 教师账号 | `std::vector<Teacher>` | 逻辑与学生账号相同 |
| 机房信息 | `std::map<int, MachineRoom>` | 便于按照机房编号查找 |
| 单条预约 | `std::map<std::string, std::string>` | 使用字段名称访问预约中的每一项信息 |
| 全部预约 | `std::map<int, std::map<std::string, std::string>>` | 使用预约编号查找、遍历和修改对应记录 |

## 七、CSV 文件格式

当前 `data/` 目录下的 CSV 文件为空。实现读写逻辑前，可以先手动写入测试数据。

### `data/student.csv`

字段：

```text
学号,姓名,密码
```

示例：

```csv
1001,张三,123456
1002,李四,123456
```

### `data/teacher.csv`

字段：

```text
职工号,姓名,密码
```

示例：

```csv
2001,王老师,123456
2002,李老师,123456
```

### `data/admin.csv`

字段：

```text
管理员姓名,密码
```

管理员姓名固定使用 `admin`。示例：

```csv
admin,123456
```

### `data/machine_room.csv`

字段：

```text
机房编号,最大容量
```

项目固定使用以下数据：

```csv
1,20
2,50
3,100
```

### `data/reservation.csv`

字段：

```text
预约编号,周几,时段,学号,学生姓名,机房编号,预约状态
```

示例：

```csv
1,1,1,1001,张三,1,1
2,3,2,1002,李四,2,2
```

数值含义：

| 字段 | 数值 | 含义 |
|------|------|------|
| `weekday` | `1` 到 `5` | 周一到周五 |
| `time_slot` | `1` | 上午 |
| `time_slot` | `2` | 下午 |
| `status` | `0` | 已取消 |
| `status` | `1` | 审核中 |
| `status` | `2` | 预约成功 |
| `status` | `3` | 审核未通过 |

从 CSV 文件读取一行数据时，将预约编号转换为 `int` 并作为外层 `map` 的键，其余字段以字符串形式写入内层 `map`：

```cpp
reservations_[reservation_id]["weekday"] = weekday;
reservations_[reservation_id]["time_slot"] = time_slot;
reservations_[reservation_id]["student_id"] = student_id;
reservations_[reservation_id]["student_name"] = student_name;
reservations_[reservation_id]["room_id"] = room_id;
reservations_[reservation_id]["status"] = status;
```

## 八、系统主流程

```text
main()
  -> 创建 ComputerRoomReservationSystem 对象
  -> 加载学生账号、教师账号、管理员账号和机房信息
  -> 调用 Run()
  -> 显示主菜单
  -> 选择身份并验证登录信息
  -> 进入对应子菜单
  -> 注销后返回主菜单
  -> 退出系统
```

主菜单：

```text
==============================
      机房预约系统
==============================
1. 学生代表登录
2. 教师登录
3. 管理员登录
4. 退出系统
==============================
请输入你的选择：
```

## 九、各身份功能流程

### 学生申请预约

```text
选择周几
  -> 选择上午或下午
  -> 选择机房
  -> 生成预约编号
  -> 状态设置为审核中
  -> 写入 reservation.csv
```

基础版完成后，可以增加冲突判断：

```text
如果日期、时段和机房均相同，
并且已有审核中或预约成功的记录，
则不允许重复申请。
```

### 学生取消预约

```text
显示当前学生可取消的预约
  -> 输入预约编号
  -> 检查预约是否属于当前学生
  -> 检查状态是否为审核中或预约成功
  -> 将状态修改为已取消
  -> 保存 reservation.csv
```

### 教师审核预约

```text
显示全部审核中的预约
  -> 输入预约编号
  -> 选择通过或不通过
  -> 修改预约状态
  -> 保存 reservation.csv
```

### 管理员添加账号

```text
选择学生账号或教师账号
  -> 输入编号、姓名和密码
  -> 检查编号是否重复
  -> 追加写入对应 CSV 文件
```

### 管理员清空预约

清空 `data/reservation.csv`，并同步清空内存中的预约容器。新的预约编号可以重新从 `1` 开始。

## 十、辅助函数建议

为了减少重复代码，可以实现：

```cpp
std::string ReservationStatusToString(const std::string& status);
std::string WeekdayToString(const std::string& weekday);
std::string TimeSlotToString(const std::string& time_slot);
```

建议集中管理文件路径：

```cpp
constexpr char kStudentFile[] = "data/student.csv";
constexpr char kTeacherFile[] = "data/teacher.csv";
constexpr char kAdminFile[] = "data/admin.csv";
constexpr char kMachineRoomFile[] = "data/machine_room.csv";
constexpr char kReservationFile[] = "data/reservation.csv";
```

注意：以上相对路径要求程序从 `computer_room_reservation_system/` 目录运行。如果从仓库根目录运行，需要调整路径或统一编译运行方式。

## 十一、推荐实现顺序

```text
1. 编写 MachineRoom，并在 reservation.h 中定义两层 map 的类型别名
2. 编写 Identity 基类
3. 编写 Student、Teacher、Administrator 的基本字段和菜单
4. 编写 ComputerRoomReservationSystem 主菜单
5. 加载学生、教师、管理员和机房 CSV 文件
6. 完成三类身份的登录验证
7. 完成管理员查看机房
8. 完成 ReservationFile 的读取、保存和清空
9. 完成学生申请预约
10. 完成查看全部预约和查看自身预约
11. 完成学生取消预约
12. 完成教师审核预约
13. 完成管理员添加账号和查看账号
14. 增加输入校验和预约冲突判断
```

优先跑通以下主线：

```text
管理员添加学生账号
  -> 学生登录
  -> 学生申请预约
  -> 教师登录
  -> 教师审核预约
  -> 学生查看预约状态
```

## 十二、开发检查清单

- [ ] 三种身份都可以完成登录和注销。
- [ ] 学生和教师编号不能重复添加。
- [ ] 日期只能选择周一到周五。
- [ ] 时段只能选择上午或下午。
- [ ] 机房编号必须存在。
- [ ] 预约编号可以正确生成。
- [ ] 修改预约状态后立即保存 CSV 文件。
- [ ] 学生不能取消其他学生的预约。
- [ ] 教师只能审核状态为审核中的预约。
- [ ] 管理员清空预约后，内存和文件内容保持一致。
- [ ] 空 CSV 文件不会导致程序异常。

## 十三、可选升级

完成基础版本后，可以继续增加：

- 输入预约人数，并检查是否超过机房容量。
- 按日期、时段和机房检查预约冲突。
- 使用 `std::set<int>` 优化账号编号查重。
- 增加 CSV 解析错误提示。
- 增加单元测试或独立的测试数据目录。
