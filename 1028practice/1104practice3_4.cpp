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

//後序運算 
int Transfer(char postfix[]){
	int num1, num2, i = 0;
	char *pt = postfix;
	
	while(*pt){
		//cout << "pt = " << *pt << endl;
		//運算元 
		if(*pt >= '0' && *pt <='9'){
			Push(*pt - '0');
		}
		
		//運算子 
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
//判斷優先度 
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

//使用堆疊將中序運算式轉成後序 
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
		
		//運算子堆疊 
		case'(':
			infix[++top] = op;
			break;
		
		case'+':case'-':case'*':case'/':
			while(Priority(infix[top]) >= Priority(op))	{
				arr[j++] =  infix[top];
				top--; // 印出後pop掉 
			}
			//存入堆疊 
			infix[++top] = op;
			break;
			
		//遇到)就輸出至( 
		case')':
			while(infix[top] != '('){
				arr[j++] =  infix[top];
				top--;
			}
			//遇到(就不輸出直接pop 
			top--;
			break;
			
		//運算元直接輸出
		default:
			arr[j++] = op;
			break;
		}
		//依序判斷字元 
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
