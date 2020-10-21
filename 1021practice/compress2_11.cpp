#include <iostream>
using namespace std;

const int a_rows = 4;
const int a_columns = 3;
const int b_rows = 100;
const int b_columns = 3;

void compress_init(int a[][a_columns])
{
    for (int i = 0; i < a_rows; i++)
        for (int j = 0; j < a_columns; j++)
            cin >> a[i][j];
}

void compress_print(int b[][b_columns]) {
    //k是算有幾個非零元素,所以要再+1才會是列的數量(有一列是放矩陣大小)
    for (int i = 0; i < b[0][2] + 1; i++)
        for (int j = 0; j < 3; j++)
            cout << b[i][j] << " ";
}

void compress_process(int a[][a_columns], int b[][b_columns]) {
    b[0][0] = a_rows;
    b[0][1] = a_columns;
    int k = 1; //從第一列開始放非零元素的位置跟值

    for (int i = 0; i < a_rows; i++)
        for (int j = 0; j < a_columns; j++)
            if (a[i][j] != 0) {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
    //k放在最後會多加一次所以要-1才會正確
    b[0][2] = k-1;

    compress_print(b);
}

int main(int argc, char* argv[])
{
    int A[a_rows][a_columns], B[b_rows][b_columns];
    compress_init(A);

    compress_process(A, B);

    system("pause");
    return 0;
}