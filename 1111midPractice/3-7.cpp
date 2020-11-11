#include <iostream>
using namespace std;

int GCD(int a, int b){
	int c = a%b;
	
	if(c!= 0)
		return GCD(b, c);
		
	else
		return b;
}

int main(int argc, char *argv[]) {
	int n1, n2;
	
	cin >> n1 >> n2;
	
	cout << GCD(n1, n2);
}
