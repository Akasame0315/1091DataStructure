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

void InfixToPostfix(char infix[], char newArr[]){
	char op;
	int i = 0, n = 0, top = 0, k = 0;
	
	while(n != 1){
		op = infix[i];
		
		switch(op){
			case '\0':
				while(top > 0)
					newArr[k++] = infix[top--];
					
				n = 1;
				break;
				
			case '(':
				infix[++top] = op;
				break;
				
			case'+':case'-':case '*': case'/':
				if(Priority(infix[top]) >= Priority(op))
					newArr[k++] = infix[top--];
					
				infix[++top] = op;
				break;
					
			case ')':
				while(infix[top] != '(')
					newArr[k++] = infix[top--];
					
				top--;
				break;
				
			default:
				newArr[k++] = op;
		}
		i++;
	}
}

int arr[] = {};
int top = -1;

void Push(int x){
	arr[++top] = x;
}

int Pop(){
	return arr[top--];
}

int Transfer(char postfix[]){
	int num1, num2;
	char *op = postfix;
	
	while(*op){
		if(*op >= '0' && *op <= '9')
			Push(*op - '0');
		
		else{
			num2 = Pop();
			num1 = Pop();
		
			switch(*op){
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
					
				default:
					break;
			}
		}
		op++;
	}
	return Pop();
}

int Eval(char infix[]){
	char newArr[20] = {};
	InfixToPostfix(infix, newArr);
	cout << Transfer(newArr);
	
}

int main(int argc, char *argv[])
{
	char itemset[20];
    scanf("%s", itemset);
    Eval(itemset);
   
}
