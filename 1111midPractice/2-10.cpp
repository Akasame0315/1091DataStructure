#include <iostream>
using namespace std;

const int a_rows = 2;
const int b_rows = 3;
const int columns = 3;

void matrix_init(int a[][columns], int b[][columns])
{              
    for(int i = 0; i < a_rows; i++)
        for(int j = 0; j < columns; j++)
            cin >> a[i][j];
    for(int i = 0; i < b_rows; i++)
        for(int j = 0; j < columns; j++)
            cin >> b[i][j];
}

void matrix_print(int arr[][columns]){
	for(int i = 0; i < a_rows; i++)
        for(int j = 0; j < b_rows; j++)
        	cout << arr[i][j] << " ";
}

void matrix_mul(int a[][columns], int b[][columns], int c[][columns]){
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 3; j++){
			int s = 0;
			for(int k = 0; k < 3; k++)
				s += a[i][k] * b[k][j];
			c[i][j] = s;
		}
	
	
    matrix_print(c);    
}

//00 = 00*00 01*10 02*20
//01 = 00*10 01*11 02*12
//02 = 00*20 01*21 02*22

int main(int argc, char *argv[])
{
    int A[a_rows][columns], B[b_rows][columns], C[a_rows][columns];
    matrix_init(A, B);
    matrix_mul(A, B, C);
}
