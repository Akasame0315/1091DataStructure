#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    int Array_Data[3][5], newArray[15], k;
    for ( int i=0; i<3; i++ )
        for ( int j=0; j<5; j++ )
            cin>>Array_Data[i][j];
    
	/*
	1.課本寫法
	k項要剛好 = i*5+j
	  newArray[0] = Array[0][0]
	  newArray[1] = Array[0][1]
	  newArray[2] = Array[0][2]
	  ...
	  newArray[5] = Array[1][0]
	  ...
	  newArray[14] = Array[2][4]
	*/
	
	for(int i = 0; i < 3; i++)
    	for(int j = 0; j < 5; j++){
    		k = i*5 + j;
			newArray[k] = Array_Data[i][j];
		}
	
	/*2.偷懶寫法	
	for(int k = 0; k < 15; k++)
		newArray[k] = Array_Data[k/5][k%5];*/ 
		
	for(int n = 0; n < 15; n++)
		cout << newArray[n] << " ";
    		
}
