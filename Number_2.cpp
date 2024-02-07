#include <bits/stdc++.h>
using namespace std;

// 全局变量定义
int num, in = -1, max_ = 100, min_ = 0, c = 1, mode;
string in2;

// 函数声明
int getNum(int n); // 用于获取一个随机数
void wantPlay(); // 显示游戏选择菜单并处理用户选择
void initGame1(); // 初始化猜数字游戏
void playGame1(); // 运行猜数字游戏
void initGame2(); // 初始化猜数字游戏（炸弹版）
void playGame2(); // 运行猜数字游戏（炸弹版）
void clearInputBuffer(); // 清除输入缓冲区中的多余字符
void clearScreen(); // 跨平台清屏函数

int main()
{
    srand(time(NULL)); // 初始化随机数生成器，确保只调用一次
    do
    {
        wantPlay();
        cout << "输入'exit'退出，否则请输入任意内容继续: ";
        cin >> in2;
        clearInputBuffer(); // 清除输入缓冲区中的多余字符
    }
    while (in2 != "exit");
    return 0;
}

int getNum(int n)
{
    return rand() % n; // 返回一个在[0, n)范围内的随机数
}

void wantPlay()
{
    clearScreen();
    // 输出游戏选择器的标题和选项
    cout << "小游戏选择器 V1.0.3[ZH-Hans]" << endl;
    cout << "Made By YuNiao." << endl;
    cout << "-1.随机" << endl;
    cout << "1.猜数字" << endl;
    cout << "2.猜数字(炸弹版)" << endl;
    cout << "更多敬请期待..." << endl;
    cout << "你想玩什么游戏(输入序号即可):";
    cin >> mode;
    clearInputBuffer(); // 清除可能的多余输入

    if(mode == -1)
    {
        mode = getNum(2) + 1; // 确保为1或2，实现随机选择
    }
    switch(mode)
    {
        case 1:
            initGame1(); // 初始化猜数字游戏
            playGame1(); // 开始游戏
            break;
        case 2:
            initGame2(); // 初始化猜数字游戏（炸弹版）
            playGame2(); // 开始游戏
            break;
        default:
            cout << "未知选项，请重新启动程序。" << endl;
            break;
    }
}

void initGame1()
{
    // 初始化游戏变量
    num = getNum(101); // 目标数字在[0,100]之间
    in = -1; // 用户输入初始化
    max_ = 100; // 最大猜测范围
    min_ = 0; // 最小猜测范围
    c = 1; // 尝试次数重置为1
}

void playGame1()
{
    clearScreen();
    cout << "猜数字小游戏 V1.1.2[ZH-Hans]" << endl;
    cout << "Made By YuNiao." << endl;
    // 游戏主循环
    while (num != in)
    {
        cout << "请输入你猜的数字(0-100): ";
        cin >> in;
        clearInputBuffer(); // 清除输入缓冲区中的多余字符
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

void initGame2()
{
    // 初始化游戏变量，逻辑与initGame1相同
    num = getNum(101);
    in = -1;
    max_ = 100;
    min_ = 0;
    c = 1;
}

void playGame2()
{
    clearScreen();
    cout << "猜数字小游戏[炸弹版] V2.0.1[ZH-Hans]" << endl;
    cout << "Made By YuNiao." << endl;
    // 游戏主循环，逻辑与playGame1相似，但有所不同
    while (num != in)
    {
        cout << "请输入你猜的数字(0-100): ";
        cin >> in;
        clearInputBuffer(); // 清除输入缓冲区中的多余字符
        if (in > 100 || in < 0)
        {
            cout << "请输入合法的数字(in >= 0 或 in <= 100)" << endl;
        }
        else if (in > num)
        {
            max_ = in;
            cout << "恭喜!...猜大了" << endl;
            c++;
        }
        else if (in < num)
        {
            min_ = in;
            cout << "恭喜!...猜小了" << endl;
            c++;
        }
        else
        {
            cout << "Haha! 你猜中了!接受惩罚吧!" << endl;
            cout << "你们一共尝试了" << c << "轮!" << endl;
            break;
        }
        cout << "剩余: " << min_ << "~" << max_ << endl;
    }
}

void clearInputBuffer() {
    // 忽略掉当前输入行剩余的所有内容，直到遇到换行符
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void clearScreen() {
    // 根据操作系统执行相应的清屏命令
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
