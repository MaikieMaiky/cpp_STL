// 员工分组案例
/**
 * 案例描述：
 * 公司招聘了10名员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
 * 员工信息有: 姓名 工资组成；部门分为：策划、美术、研发
 * 随机给10名员工分配部门和工资
 * 通过multimap进行信息的保存
 * 分部门显示员工信息
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

enum class department
{
    plan,
    art,
    development
};

class worker
{
public:
    worker(string name, int salary) : name_(name), salary_(salary) {}

    string name_;
    int salary_;
};

// 1. 创建员工
void create_worker(vector<worker>& workers)
{
    string name_seed = "ABCDEFGHIJ";
    for (const char& i : name_seed)
    {
        string name = "worker";
        name += i;
        // 薪水分配范围1000~10999
        workers.push_back(worker(name, rand() % 10000 + 1000));
    }
}

// 2. 打印员工
void print_worker(vector<worker>& workers)
{
    for (const auto& worker : workers)
    {
        cout << "name: " << worker.name_ << " salary: " << worker.salary_ << endl;
    }
    cout << endl;
}

// 3. 分配部门
void assign_department(vector<worker>& workers, multimap<department, worker>& worker_map)
{
    for (const auto& wk : workers)
    {
        department dep = (department)(rand() % 3);
        worker_map.insert({dep, wk});
    }
}

// 4. 按部门查询+打印
void print_department(multimap<department, worker>& worker_map, department dep)
{
    for (auto it = worker_map.lower_bound(dep); it != worker_map.upper_bound(dep); it++)
    {
        cout << "name: " << it->second.name_ 
        << " salary: " << it->second.salary_ << " department: ";
        switch (dep)
        {
            case department::plan:
                cout << "plan";
                break;
            case department::art:
                cout << "art";
                break;
            case department::development:
                cout << "development";
                break;
        }
        cout << endl;
    }
    cout << "--------------------------------" << endl;
}

void test0()
{
    // 设置随机数种子
    srand((unsigned int)time(NULL));

    // 员工入职
    vector<worker> workers;
    create_worker(workers);
    print_worker(workers);


    // 分配部门 multimap
    multimap<department, worker> worker_map;
    assign_department(workers, worker_map);


    // 按部门查询+打印
    print_department(worker_map, department::plan);
    print_department(worker_map, department::art);
    print_department(worker_map, department::development);


}

int main()
{
    test0();
    return 0;
}