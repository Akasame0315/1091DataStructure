#include <iostream>
using namespace std;

int array[10], top = -1;

void Push(int x) {
	top++;
	array[top] = x;
	//cout << "array[" << top << "] = " << array[top] << endl;
}

int Pop() {
	return array[top--];
}

//��ǹB�� 
int Transfer(char postfix[]){
	int num1, num2, i = 0;
	char *pt = postfix;
	
	while(*pt){
		//cout << "pt = " << *pt << endl;
		//�B�⤸ 
		if(*pt >= '0' && *pt <='9'){
			Push(*pt - '0');
		}
		
		//�B��l 
		else{
			num2 = Pop();
			//cout << "pop num2: " << num2 << " ";
			num1 = Pop();
			//cout << "pop num1: " << num1 << endl;
			
			switch(*pt){
				case'+':
					Push(num1 + num2);
					break;
					
				case'-':
					Push(num1 - num2);
					break;
					
				case'*':
					Push(num1 * num2);
					break;
					
				case'/':
					Push(num1 / num2);
					break;
					
				default:
					return -1;
					break;
			} 
		}
		pt++;
	}
	return Pop();
}
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
void InfixToPostfix(char infix[],char arr[]){
	char op;
	int i = 0, top = 0, j = 0;
	
	while(infix[top] != '\0'){
		op = infix[i];
		switch(op){
		case'\0':
			while(top>0){
				arr[j++] = infix[top];
				top--;
			}
		
		//�B��l���| 
		case'(':
			infix[++top] = op;
			break;
		
		case'+':case'-':case'*':case'/':
			while(Priority(infix[top]) >= Priority(op))	{
				arr[j++] =  infix[top];
				top--; // �L�X��pop�� 
			}
			//�s�J���| 
			infix[++top] = op;
			break;
			
		//�J��)�N��X��( 
		case')':
			while(infix[top] != '('){
				arr[j++] =  infix[top];
				top--;
			}
			//�J��(�N����X����pop 
			top--;
			break;
			
		//�B�⤸������X
		default:
			arr[j++] = op;
			break;
		}
		//�̧ǧP�_�r�� 
		i++;
	}
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
