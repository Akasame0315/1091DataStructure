#include <iostream>
using namespace std;

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
void InflixToPostfix(char infix[]){
	char op;
	int i = 0, top = 0;
	do{
		op = infix[i];
		switch(op){
		case'\0':
			while(top>0){
				cout << infix[top];
				top--;
			}
		
		//運算子堆疊 
		case'(':
			infix[++top] = op;
			break;
		
		case'+':case'-':case'*':case'/':
			while(Priority(infix[top]) >= Priority(op))	{
				cout << infix[top];
				top--; // 印出後pop掉 
			}
			//存入堆疊 
			infix[++top] = op;
			break;
			
		//遇到)就輸出至( 
		case')':
			while(infix[top] != '('){
				cout << infix[top];
				top--;
			}
			//遇到(就不輸出直接pop 
			top--;
			break;
			
		//運算元直接輸出
		default:
			cout << op;
			 break;
		}
		//依序判斷字元 
		i++;
	}while(infix[top] != '\0');
}

int main(int argc, char *argv[])
{
	char itemset[20];
	scanf("%s", itemset);
	InflixToPostfix(itemset);
}
