#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h> // 用于Sleep函数
using namespace std;

// 全局变量
int num, in = -1, max_ = 100, min_ = 0, c = 0;
string in2;

// 函数声明
void initGame();
void playGame();

int main()
{
    do
    {
        initGame(); // 初始化游戏
        playGame(); // 开始游戏
        cout << "输入'exit'退出，否则请输入任意内容继续: ";
        cin >> in2;
    }
    while (in2 != "exit");
    return 0;
}
void initGame()
{
    srand((unsigned)time(NULL)); // 初始化随机数种子
    num = rand() % 101; // 生成一个0到100之间的随机数
    in = -1;
    max_ = 100;
    min_ = 0;
    c = 0; // 尝试次数重置为0
}
void playGame()
{
    system("cls");
    cout << "猜数字小游戏 V1.0.2[ZH-Hans]" << endl;
    cout << "Made By YuNiao." << endl;
    while (num != in)
    {
        cout << "请输入你猜的数字(0-100): ";
        cin >> in;
        if (in > 100 || in < 0)
        {
            cout << "请输入合法的数字(in >= 0 或 in <= 100)" << endl;
        }
        else if (in > num)
        {
            max_ = in;
            cout << "大了" << endl;
            c++;
        }
        else if (in < num)
        {
            min_ = in;
            cout << "小了" << endl;
            c++;
        }
        else
        {
            cout << "Bingo! 你太厉害了!" << endl;
            cout << "你一共尝试了" << c << "轮!" << endl;
            break;
        }
        cout << "提示: " << min_ << "~" << max_ << endl;
    }
}
