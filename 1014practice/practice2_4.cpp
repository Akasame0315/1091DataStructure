#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    int Score[4][5];
    double sum[5];
    
    //輸入成績 
    for ( int i=0; i<4; i++ )
        for ( int j=0; j<5; j++ )
            cin>>Score[i][j];
    
	//成績加總        
    for ( int i=0; i<5; i++ ){
    	for ( int j=0; j<4; j++ )
			sum[i] += Score[j][i];
			
		cout << "object" << i+1 << " average: " << sum[i] / 4.0 << endl;
	}
	
}
