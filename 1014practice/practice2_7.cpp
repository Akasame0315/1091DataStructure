#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    int Array_Data[3][5], newArray[15], k;
    for ( int i=0; i<3; i++ )
        for ( int j=0; j<5; j++ )
            cin>>Array_Data[i][j];
            
    /*
	1.課本寫法
	k項要剛好 = i + j*3
	newArray[0] = Array[0][0]
	newArray[1] = Array[1][0]
	newArray[2] = Array[2][0]
	newArray[3] = Array[0][1]
	...
	newArray[14] = Array[2][4]
	*/
	
	for(int i = 0; i < 3; i++)
    	for(int j = 0; j < 5; j++){
    		k = i + j * 3;
			newArray[k] = Array_Data[i][j];
		}
		
	/*
	偷懶寫法 
	
	for(int k = 0; k < 15; k++){
		newArray[k] = Array_Data[k%3][k/3]; 
		cout << newArray[k] << " ";
	}*/
	for(int k = 0; k < 15; k++)
		cout << newArray[k] << " ";
}
