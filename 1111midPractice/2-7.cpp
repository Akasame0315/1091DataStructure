#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    int Array_Data[3][5], newArr[15];
    for ( int i=0; i<3; i++ )
        for ( int j=0; j<5; j++ )
            cin>>Array_Data[i][j];
            
    for ( int i=0; i<3; i++ )
        for ( int j=0; j<5; j++ )
        	newArr[i + j * 3] = Array_Data[i][j];
	
	for ( int i=0; i<15; i++ )
		cout << newArr[i] << " ";
}
