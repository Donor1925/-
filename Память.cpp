#include <iostream>
#include <ctime>
#include <vector>
#include <Windows.h>
using namespace std;


int main()
{

    setlocale(LC_ALL, "Russian");

    int start = clock();//начало времени

    
    int a[8], c = 0;
    for (int i = 0; i < 8; ++i)
    {
        a[i] = 0;
    }
    int n, mat[4][4];
    srand((unsigned)time(NULL));
    for (int i = 0; i < 4; ++i)//генерация поля
    {
        for (int j = 0; j < 4; ++j)//генерация чисел
        {
            n = rand() % 8; //генерация чисел до 8-и пар
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
    }//подсказка на верху
    for (int i = 0; i < 4; ++i)///ряд
    {
        for (int j = 0; j < 4; ++j)///колонна
            cout << mat[i][j] << ((j + 1 == 4) ? '\n' : ' ');
    }
    cout << endl;
    cout << "   " << "1" << "  " << "2" << "  " << "3" << "  " << "4" << endl;
    for (int i = 0; i < 4; ++i)//поле 4х4
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
    //сама игра

    int temp = 0; // перевороты карт

    int game = 0;

    vector<int>v;
    while (game == 0)
    {
        
        int x1, y1, x2, y2, c = 0;
        cout << "Введите номер колонны первой ячейки  " << endl;
        cin >> x1;
        cout << "Введите номер ряда первой ячейки " << endl;
        cin >> y1;
        cout << "Введите номер колонны второй ячейки " << endl;
        cin >> x2;
        cout << "Введите номер колонны второй ячейки " << endl;
        cin >> y2;
        if (mat[x1][y1] == mat[x2][y2])
        {
            cout << "Верно! Продолжаем" << endl;
            v.push_back(mat[x1][y1]);//массив поля со звездами после ввода координат
            c += 1;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (find(v.begin(), v.end(), mat[i][j]) != v.end())
                        cout << mat[i][j] << "  ";//пространство между звезд
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
            
             cout << "Не верно! Попробуй еще раз" << endl;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if ((i == x1 && j == y1) || (i == x2 && j == y2) || (find(v.begin(), v.end(), mat[i][j]) != v.end())) //если числа разные, то ставим в исходное
                        cout << mat[i][j] << "  "; //пространство между звезд
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
                for (int j = 0; j < 4; j++)//вывод на в консоль перед вводом чисел
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
        cout << "чтобы продолжить нажмите 0" << endl;
        cout << "чтобы закончить игру нажмите 1" << endl;
        cin >> game;
        cout << "количество переворотов карт :" << temp << endl;

        int end = clock();//конец времени
        int t = (end - start) / CLOCKS_PER_SEC;//считаем время игры

        cout << "время игры :" << t << "сек" << endl;
    }
    return 0;
}
