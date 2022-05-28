#include <iostream>
#include <ctime>
#include <vector>
#include <Windows.h>
using namespace std;


int main()
{

    setlocale(LC_ALL, "Russian");

    int start = clock();//������ �������

    
    int a[8], c = 0;
    for (int i = 0; i < 8; ++i)
    {
        a[i] = 0;
    }
    int n, mat[4][4];
    srand((unsigned)time(NULL));
    for (int i = 0; i < 4; ++i)//��������� ����
    {
        for (int j = 0; j < 4; ++j)//��������� �����
        {
            n = rand() % 8; //��������� ����� �� 8-� ���
            if (a[n] == 2)
            {
                --j;
                continue;
            }
            else
            {
                mat[i][j] = n + 1;
                a[n]++;
            }
        }
    }//��������� �� �����
    for (int i = 0; i < 4; ++i)///���
    {
        for (int j = 0; j < 4; ++j)///�������
            cout << mat[i][j] << ((j + 1 == 4) ? '\n' : ' ');
    }
    cout << endl;
    cout << "   " << "1" << "  " << "2" << "  " << "3" << "  " << "4" << endl;
    for (int i = 0; i < 4; ++i)//���� 4�4
    {
        for (int j = 0; j < 4; ++j)
        {
            if (j == 0)
            {
                cout << c << "  ";
                c++;
            }
            cout << "*" << "  ";
        }
        cout << endl;
    }
    //���� ����

    int temp = 0; // ���������� ����

    int game = 0;

    vector<int>v;
    while (game == 0)
    {
        
        int x1, y1, x2, y2, c = 0;
        cout << "������� ����� ������� ������ ������  " << endl;
        cin >> x1;
        cout << "������� ����� ���� ������ ������ " << endl;
        cin >> y1;
        cout << "������� ����� ������� ������ ������ " << endl;
        cin >> x2;
        cout << "������� ����� ������� ������ ������ " << endl;
        cin >> y2;
        if (mat[x1][y1] == mat[x2][y2])
        {
            cout << "�����! ����������" << endl;
            v.push_back(mat[x1][y1]);//������ ���� �� �������� ����� ����� ���������
            c += 1;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (find(v.begin(), v.end(), mat[i][j]) != v.end())
                        cout << mat[i][j] << "  ";//������������ ����� �����
                    else
                        cout << "*" << "  ";
                }
                cout << endl;
            }
            temp += 2;
            Beep(5000, 50);
        }
        else
        {
            
             cout << "�� �����! �������� ��� ���" << endl;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if ((i == x1 && j == y1) || (i == x2 && j == y2) || (find(v.begin(), v.end(), mat[i][j]) != v.end())) //���� ����� ������, �� ������ � ��������
                        cout << mat[i][j] << "  "; //������������ ����� �����
                    else
                    {
                        cout << "*" << "  ";
                    }

                }
                cout << endl;
                
                
            }
            cout << endl << endl;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)//����� �� � ������� ����� ������ �����
                {
                    if (find(v.begin(), v.end(), mat[i][j]) != v.end())
                        cout << mat[i][j] << "  ";
                    else

                        cout << "*" << "  ";
                }
                cout << endl;
            }
            temp += 2;
            Beep(500, 50);
        }
        cout << "����� ���������� ������� 0" << endl;
        cout << "����� ��������� ���� ������� 1" << endl;
        cin >> game;
        cout << "���������� ����������� ���� :" << temp << endl;

        int end = clock();//����� �������
        int t = (end - start) / CLOCKS_PER_SEC;//������� ����� ����

        cout << "����� ���� :" << t << "���" << endl;
    }
    return 0;
}
