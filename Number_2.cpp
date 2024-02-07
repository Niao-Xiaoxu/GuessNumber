#include <bits/stdc++.h>
using namespace std;

// ȫ�ֱ�������
int num, in = -1, max_ = 100, min_ = 0, c = 1, mode;
string in2;

// ��������
int getNum(int n); // ���ڻ�ȡһ�������
void wantPlay(); // ��ʾ��Ϸѡ��˵��������û�ѡ��
void initGame1(); // ��ʼ����������Ϸ
void playGame1(); // ���в�������Ϸ
void initGame2(); // ��ʼ����������Ϸ��ը���棩
void playGame2(); // ���в�������Ϸ��ը���棩
void clearInputBuffer(); // ������뻺�����еĶ����ַ�
void clearScreen(); // ��ƽ̨��������

int main()
{
    srand(time(NULL)); // ��ʼ���������������ȷ��ֻ����һ��
    do
    {
        wantPlay();
        cout << "����'exit'�˳��������������������ݼ���: ";
        cin >> in2;
        clearInputBuffer(); // ������뻺�����еĶ����ַ�
    }
    while (in2 != "exit");
    return 0;
}

int getNum(int n)
{
    return rand() % n; // ����һ����[0, n)��Χ�ڵ������
}

void wantPlay()
{
    clearScreen();
    // �����Ϸѡ�����ı����ѡ��
    cout << "С��Ϸѡ���� V1.0.3[ZH-Hans]" << endl;
    cout << "Made By YuNiao." << endl;
    cout << "-1.���" << endl;
    cout << "1.������" << endl;
    cout << "2.������(ը����)" << endl;
    cout << "���ྴ���ڴ�..." << endl;
    cout << "������ʲô��Ϸ(������ż���):";
    cin >> mode;
    clearInputBuffer(); // ������ܵĶ�������

    if(mode == -1)
    {
        mode = getNum(2) + 1; // ȷ��Ϊ1��2��ʵ�����ѡ��
    }
    switch(mode)
    {
        case 1:
            initGame1(); // ��ʼ����������Ϸ
            playGame1(); // ��ʼ��Ϸ
            break;
        case 2:
            initGame2(); // ��ʼ����������Ϸ��ը���棩
            playGame2(); // ��ʼ��Ϸ
            break;
        default:
            cout << "δ֪ѡ���������������" << endl;
            break;
    }
}

void initGame1()
{
    // ��ʼ����Ϸ����
    num = getNum(101); // Ŀ��������[0,100]֮��
    in = -1; // �û������ʼ��
    max_ = 100; // ���²ⷶΧ
    min_ = 0; // ��С�²ⷶΧ
    c = 1; // ���Դ�������Ϊ1
}

void playGame1()
{
    clearScreen();
    cout << "������С��Ϸ V1.1.2[ZH-Hans]" << endl;
    cout << "Made By YuNiao." << endl;
    // ��Ϸ��ѭ��
    while (num != in)
    {
        cout << "��������µ�����(0-100): ";
        cin >> in;
        clearInputBuffer(); // ������뻺�����еĶ����ַ�
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

void initGame2()
{
    // ��ʼ����Ϸ�������߼���initGame1��ͬ
    num = getNum(101);
    in = -1;
    max_ = 100;
    min_ = 0;
    c = 1;
}

void playGame2()
{
    clearScreen();
    cout << "������С��Ϸ[ը����] V2.0.1[ZH-Hans]" << endl;
    cout << "Made By YuNiao." << endl;
    // ��Ϸ��ѭ�����߼���playGame1���ƣ���������ͬ
    while (num != in)
    {
        cout << "��������µ�����(0-100): ";
        cin >> in;
        clearInputBuffer(); // ������뻺�����еĶ����ַ�
        if (in > 100 || in < 0)
        {
            cout << "������Ϸ�������(in >= 0 �� in <= 100)" << endl;
        }
        else if (in > num)
        {
            max_ = in;
            cout << "��ϲ!...�´���" << endl;
            c++;
        }
        else if (in < num)
        {
            min_ = in;
            cout << "��ϲ!...��С��" << endl;
            c++;
        }
        else
        {
            cout << "Haha! �������!���ܳͷ���!" << endl;
            cout << "����һ��������" << c << "��!" << endl;
            break;
        }
        cout << "ʣ��: " << min_ << "~" << max_ << endl;
    }
}

void clearInputBuffer() {
    // ���Ե���ǰ������ʣ����������ݣ�ֱ���������з�
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void clearScreen() {
    // ���ݲ���ϵͳִ����Ӧ����������
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
