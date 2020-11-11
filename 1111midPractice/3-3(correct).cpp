#include <iostream>
using namespace std;

int arr[10];
int Top = -1;

void Push(int x){
	arr[++Top] = x;
}

int Pop(){
	return arr[Top--];
}

int Transfer(char postfix[]){
	char *pt = postfix;
	int num1, num2;
	
	while(*pt){
		if(*pt >= '0' && *pt <= '9')
			Push(*pt - '0');
	
		else{
			num2 = Pop();
			num1 = Pop();
			
			switch(*pt){
				
				case '+':
					Push(num1 + num2);
					break;
	
				case '-':
					Push(num1 - num2);
					break;
					
				case '*':
					Push(num1 * num2);
					break;
					
				case '/':
					Push(num1 / num2);
					break;		
			
			
			}
		}
		*pt++;
	}
	cout << Pop();
}

int main(int argc, char *argv[])
{
   char itemset[20];
   scanf("%s", itemset);
   Transfer(itemset);
}
