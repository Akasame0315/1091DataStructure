#include <iostream>
using namespace std;

const int a_rows = 2;
const int b_rows = 3;
const int columns = 3;

//初始值
void matrix_init(int a[][columns], int b[][columns])
{
    for (int i = 0; i < a_rows; i++)
        for (int j = 0; j < columns; j++)
            cin >> a[i][j];
    for (int i = 0; i < b_rows; i++)
        for (int j = 0; j < columns; j++)
            cin >> b[i][j];
}

//輸出函式
void matrix_print(int arr[][columns]) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            cout << arr[i][j] << " ";
}
/*
a
0,0 0,1 0,2
1,0 1,1 1,2
b
0,0 0,1 0,2
1,0 1,1 1,2
2,0 2,1 2,2
c
00 = 00 * 00 + 01 * 10 + 02 * 20
01 = 00 * 01 + 01 * 11 + 02 * 21
02 = 00 * 20 + 01 * 12 + 02 * 22
10 = 10 * 00 + 11 * 10 + 12 * 20
11 = 10 * 01 + 11 * 11 + 12 * 21
12 = 10 * 02 + 11 * 12 + 12 * 22*/

//相乘函式
void matrix_mul(int a[][columns], int b[][columns], int c[][columns]) {

    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < 3; j++) {
            //加一次C的元素就把sum歸零
            int sum = 0;
            for (int k = 0; k < 3; k++)
                sum += a[i][k] * b[k][j];
            c[i][j] = sum;
        }
    matrix_print(c);
}

//主程式
int main(int argc, char* argv[])
{
    int A[a_rows][columns], B[b_rows][columns], C[a_rows][columns];
    matrix_init(A, B);

    matrix_mul(A, B, C);
}