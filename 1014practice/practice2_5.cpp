#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    int Score[3][4][5];
    int stuSum[4] = {}, scoreSum[5] = {};
    
    for ( int k=0; k<3; k++ )
        for ( int i=0; i<4; i++ )
            for ( int j=0; j<5; j++ )
                cin>>Score[k][i][j];
	
    //i是學生, k是月考次數, j是科目 
    for(int i = 0; i < 4; i++){
    	for(int k = 0; k < 3; k++)
    		for(int j = 0; j < 5; j++)
    			stuSum[i] += Score[k][i][j];
    			
		cout << "Student sumScore: " << stuSum[i] << " ";
	}
	cout << endl;
	
	for(int j = 0; j < 5; j++){
    	for(int k = 0; k < 3; k++)
    		for(int i = 0; i < 4; i++)
    			scoreSum[j] += Score[k][i][j];
    			
		cout << "Object sumScore: " << scoreSum[j] << " ";
	} 
    	
    
}
