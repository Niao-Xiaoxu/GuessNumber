#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h> // ����Sleep����
using namespace std;

// ȫ�ֱ���
int num, in = -1, max_ = 100, min_ = 0, c = 0;
string in2;

// ��������
void initGame();
void playGame();

int main()
{
    do
    {
        initGame(); // ��ʼ����Ϸ
        playGame(); // ��ʼ��Ϸ
        cout << "����'exit'�˳��������������������ݼ���: ";
        cin >> in2;
    }
    while (in2 != "exit");
    return 0;
}
void initGame()
{
    srand((unsigned)time(NULL)); // ��ʼ�����������
    num = rand() % 101; // ����һ��0��100֮��������
    in = -1;
    max_ = 100;
    min_ = 0;
    c = 0; // ���Դ�������Ϊ0
}
void playGame()
{
    system("cls");
    cout << "������С��Ϸ V1.0.2[ZH-Hans]" << endl;
    cout << "Made By YuNiao." << endl;
    while (num != in)
    {
        cout << "��������µ�����(0-100): ";
        cin >> in;
        if (in > 100 || in < 0)
        {
            cout << "������Ϸ�������(in >= 0 �� in <= 100)" << endl;
        }
        else if (in > num)
        {
            max_ = in;
            cout << "����" << endl;
            c++;
        }
        else if (in < num)
        {
            min_ = in;
            cout << "С��" << endl;
            c++;
        }
        else
        {
            cout << "Bingo! ��̫������!" << endl;
            cout << "��һ��������" << c << "��!" << endl;
            break;
        }
        cout << "��ʾ: " << min_ << "~" << max_ << endl;
    }
}
