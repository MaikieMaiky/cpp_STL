#include "speech_manager.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    system("cls");
    // 随机数种子
    srand((unsigned int)time(nullptr));
    speech_manager sm;
    int choice = 0;
    while (true)
    {
        sm.show_menu();
        cin >> choice;
        switch (choice)
        {
            // 开始演讲比赛
            case 1:
                sm.start_speech();
                break;
            // 查看往届记录
            case 2:
                // sm.show_record();
                break;
            // 清空比赛记录
            case 3:
                // sm.clear_record();
                break;
            // 退出系统
            case 0:
                sm.exit_system();
                break;
            default:
                cout << "invalid input, please try again" << endl;
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}