#include <iostream>
using namespace std;

const int rows = 4;
const int columns = 4;

//初始值
void matrix_init(int arr[][columns])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cin >> arr[i][j];
}

//輸出結果
void matrix_print(int arr[][columns]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cout << arr[i][j] << " ";
}

//轉置函式
void matrix_transpose(int arr[][columns]) {
    int newArr[rows][columns];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            newArr[i][j] = arr[j][i];

    //輸出
    matrix_print(newArr);
}

//主程式
int main(int argc, char* argv[])
{
    int A[rows][columns];
    matrix_init(A);

    matrix_transpose(A);

    system("pause");
    return 0;
}