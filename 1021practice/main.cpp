#include <iostream>
using namespace std;

const int rows = 4;
const int columns = 4;

//��l��
void matrix_init(int arr[][columns])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cin >> arr[i][j];
}

//��X���G
void matrix_print(int arr[][columns]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cout << arr[i][j] << " ";
}

//��m�禡
void matrix_transpose(int arr[][columns]) {
    int newArr[rows][columns];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            newArr[i][j] = arr[j][i];

    //��X
    matrix_print(newArr);
}

//�D�{��
int main(int argc, char* argv[])
{
    int A[rows][columns];
    matrix_init(A);

    matrix_transpose(A);

    system("pause");
    return 0;
}