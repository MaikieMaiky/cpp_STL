#include "speech_manager.h"
#include <iostream>
using namespace std;


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
