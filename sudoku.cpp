#include <iostream>
#include <cstdio>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int arr[9][9];
int Checker(int a, int b, int c)
{
    int i, j;
    for (i = a, j = 0; j < 9; j++)
    {
        if (c == arr[i][j] && j != b)
            return 0;
    }
    for (i = 0, j = b; i < 9; i++)
    {
        if (c == arr[i][j] && i != a)
            return 0;
    }
    int m = a / 3, n = b / 3;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (c == arr[m * 3 + i][n * 3 + j] && (m * 3 + i) != a && (n * 3 + j) != b)
                return 0;
        }
    }
    return 1;
}
void Maker()
{
    srand(time(NULL));
    int r = 20 + rand() % 10, k, l;
    for (int i = 0; i < r; i++)
    {
        int k = rand() % 8, l = rand() % 8, s = 0;
        do
        {
            s = 0;
            arr[k][l] = 1 + rand() % 8;
            s = Checker(k, l, arr[k][l]);
        } while (s == 0);
    }
}
void Printer()
{
    for (int i = 0; i < 9; i++)
    {
        cout << "\t\t\t";
        cout << "|";
        for (int j = 0; j < 9; j++)
        {
            if (arr[i][j] == 0)
                cout << "_ ";
            else if (j < 8)
                cout << arr[i][j] << " ";
        }
        cout << "|" << endl;
    }
}
void Taker()
{
    int a[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> a[i][j];
            if (arr[i][j] != 0)
            {
                if (a[i][j] != arr[i][j])
                {
                    printf("You are changing number in the question\n");
                    return;
                }
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            arr[i][j] = a[i][j];
    }
}
int main()
{
    int i, j, a;
    printf("\n\n-----------------------------Welcome to the SUDOKU-------------------------------\n\n");
    Maker();
    Printer();
    int choice;
    printf("Want to : \n\t 1)Enter the whole table \n\t 2)Edit the elements with their respective positions\n");
    scanf("%d", &choice);
    if (choice == 1)
        Taker();
    else if (choice == 2)
    {
        printf("Enter the row and column number and then number you want to enter");
        cin >> a;
    }
    return 0;
}