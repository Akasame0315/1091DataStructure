#include <iostream>
using namespace std;

void Towers(int n, char a, char b, char c){
	if(n > 0){
		//先將n-1個盤子從a搬到b
		Towers(n-1, a, c, b);
		cout << "Move disk " << n << " from " << a << " to " << c << endl;
		Towers(n-1, b, a, c);
	}
}

int main(int argc, char *argv[]) {
	int input;
	cin >> input;
	
	Towers(input, 'A', 'B', 'C');
}
