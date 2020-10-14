#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    int Score[4][5];
    double sum[4] = {};
    
    //輸入成績 
    for ( int i=0; i<4; i++ )
        for ( int j=0; j<5; j++ )
            cin>>Score[i][j];
    
	//加總每位學生成績        
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 5; j++){
			sum[i] += Score[i][j];
		}
		cout << "student"<< i+1 << " average: " << sum[i]/5.0 << endl;
	}
		
}
