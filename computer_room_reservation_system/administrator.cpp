#include "administrator.h"
#include <iostream>
#include "global_file.h"
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

// for each使用的打印函数
void print_teacher(Teacher &teacher)
{
    cout << "Teacher ID: " << teacher.id_ << " " << "Teacher Name: " << teacher.name_ << " " << "Teacher Password: " << teacher.password_ << endl;
}
void print_student(Student &student)
{
    cout << "Student ID: " << student.id_ << " " << "Student Name: " << student.name_ << " " << "Student Password: " << student.password_ << endl;
}

// 默认构造
Administrator::Administrator()
{
    InitVector();
}

// 有参构造
Administrator::Administrator(string name, string password) : Identity(name, password)
{
    InitVector();
}

// 显示子菜单
void Administrator::ShowMenu()
{
    cout << "==========================================" << endl;
    cout << "|      Administrator Menu                |" << endl;
    cout << "|=========================================" << endl;
    cout << "|      1. Add Account                    |" << endl;
    cout << "|      2. View Account                   |" << endl;
    cout << "|      3. View Machine Room              |" << endl;
    cout << "|      4. Clear Reservation              |" << endl;
    cout << "|      5. Exit                           |" << endl;
    cout << "==========================================" << endl;
    cout << "Please input your choice: ";
}


// 添加账号 先不考虑重复账号 保留注释以便后续实现
void Administrator::AddAccount()
{
    // 1.choose the type of account: Teacher or Student
    cout << "Please input the type of account: " << endl;
    cout << "1. Teacher" << endl;
    cout << "2. Student" << endl;


    // 2.input the account information
    string filename = "";
    string tip = "";
    int id = 0;
    string name;
    string password;
    int type = 0;
    cin >> type;
    if (type == 1)
    {
        // 添加教师账号
        filename = kTeacherFile;
        tip = "Please input the teacher id: ";
    }
    else if (type == 2)
    {
        // 添加学生账号
        filename = kStudentFile;
        tip = "Please input the student id: ";
    }
    else
    {
        cout << "Invalid input, please try again" << endl;
        return;
    }
    // 输入账号信息
    cout << tip;
    cin >> id;

    // 3.check the account information is already exist
    if (type == 1)
    {
        for (auto &teacher : teacher_)
        {
            if (teacher.id_ == id)
            {
                cout << "Teacher already exists" << endl;
                return;
            }
        }
    }
    else if (type == 2)
    {
        for (auto &student : student_)
        {
            if (student.id_ == id)
            {
                cout << "Student already exists" << endl;
                return;
            }
        }
    }

    cout << "Please input the name: ";
    cin >> name;
    cout << "Please input the password: ";
    cin >> password;


    
    // 4.save the account information to the file
    // 打开文件 append
    ofstream ofs;
    ofs.open(filename, ios::app);
    if (!ofs.is_open())
    {
        cout << "File open error" << endl;
        return;
    }
    ofs << id << "," << name << "," << password << endl;
    ofs.close();
    cout << "Add account successfully" << endl;

    // 5.add the account information to the vector
    if (type == 1)
    {
        teacher_.push_back(Teacher(name, password, id));
    }
    else if (type == 2)
    {
        student_.push_back(Student(name, password, id));
    }

    return;
}

// 查看账号
void Administrator::ViewAccount()
{
    // 1. choose the account you want to view: Teacher or Student
    cout << "Please input the type of account you want to view: " << endl;
    cout << "1. Teacher" << endl;
    cout << "2. Student" << endl;
    int type = 0;
    cin >> type;
    if (type == 1)
    {
        for_each(teacher_.begin(), teacher_.end(), print_teacher);
    }
    else if (type == 2)
    {
        for_each(student_.begin(), student_.end(), print_student);
    }
    else
    {
        cout << "Invalid input, please try again" << endl;
        return;
    }
}

// 查看机房
void Administrator::ViewMachineRoom()
{
}

// 清空预约
void Administrator::ClearReservation()
{
}

// 初始化容器
void Administrator::InitVector()
{
    string filename = "";
    string line;
    // 读取教师文件
    filename = kTeacherFile;
    ifstream ifs;
    ifs.open(filename, ios::in);
    if (!ifs.is_open())
    {
        cout << "File open error" << endl;
        return;
    }
    while (getline(ifs, line))
    {
        stringstream ss(line);
        Teacher teacher;
        char comma;
        ss >> teacher.id_ >> comma;
        getline(ss, teacher.name_, ',');
        getline(ss, teacher.password_);
        teacher_.push_back(teacher);
    }
    ifs.close();

    
    // 读取学生文件
    filename = kStudentFile;
    ifs.open(filename, ios::in);
    if (!ifs.is_open())
    {
        cout << "File open error" << endl;
        return;
    }
    while (getline(ifs, line))
    {
        stringstream ss(line);
        Student student;
        char comma;
        ss >> student.id_ >> comma;
        getline(ss, student.name_, ',');
        getline(ss, student.password_);
        student_.push_back(student);
    }
    ifs.close();

    // 打印输出调试信息
    cout << "Student size: " << student_.size() << endl;
    cout << "Teacher size: " << teacher_.size() << endl;
}