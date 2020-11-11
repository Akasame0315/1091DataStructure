#include <iostream>
using namespace std;

//�P�_�u���� 
int Priority(char op){
	int order; 
	
	switch(op){
		case'+':
			order = 1;
			break;
		case'-':
			order = 1;
			break;
		case'*':
			order = 2;
			break;
		case'/':
			order = 2;
			break;
			
		default:
			 order = 0;
			 break;
	}
	return order;
}

//�ϥΰ��|�N���ǹB�⦡�ন��� 
char InfixToPostfix(char infix[]){
	char op;
	int i = 0, top = 0;
	while(1){
		op = infix[i];
		switch(op){
		case'\0':
			while(top>0){
				cout << infix[top];
				top--;
				return 0;
			}
		
		//�B��l���| 
		case'(':
			infix[++top] = op;
			break;
		
		case'+':case'-':case'*':case'/':
			while(Priority(infix[top]) >= Priority(op))	{
				cout << infix[top];
				top--; // �L�X��pop�� 
			}
			//�s�J���| 
			infix[++top] = op;
			break;
			
		//�J��)�N��X��( 
		case')':
			while(infix[top] != '('){
				cout << infix[top];
				top--;
			}
			//�J��(�N����X����pop 
			top--;
			break;
			
		//�B�⤸������X
		default:
			cout << op;
			 break;
		}
		//�̧ǧP�_�r�� 
		i++;
	}
}

int main(int argc, char *argv[])
{
	char itemset[20];
	scanf("%s", itemset);
	InfixToPostfix(itemset);
}