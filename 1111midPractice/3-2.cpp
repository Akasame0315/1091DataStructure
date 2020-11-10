#include <iostream>
using namespace std;

int Priority(char op){
	switch(op){
		case '+':case '-':
			return 1;
			break;
			
		case '*':case '/':
			return 2;
			break;
			
		default:
			return 0;
	}
}

void InfixToPostfix(char infix[]){
	char op;
	int i = 0, n = 0, Top = 0;
	
	while(n != 1){
		op = infix[i];
		
		switch(op){
			case '\0':
				while(Top > 0)
					cout << infix[Top--];
				n = 1;
				break;
				
			case '(':
				infix[++Top] = op;
				break;
				
			case '+':case '-':case '*':case '/':
				while(Priority(infix[Top]) >= Priority(op))
					cout << infix[Top--];
					
				infix[++Top] = op;
				break;
		
			case ')':
				while(infix[Top] != '(')
					cout << infix[Top--];
					
				Top--;
				break;
				
			default:
				cout << op;
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
   char itemset[20];
   scanf("%s", itemset);
   InfixToPostfix(itemset);
}
