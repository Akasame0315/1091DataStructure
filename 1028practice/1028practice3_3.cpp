#include <iostream>
using namespace std;

int array[10], top = -1;

void Push(int x) {
	top++;
	array[top] = x;
}

int Pop() {
	return array[top--];
}

int Transfer(char postfix[]){
	int num1, num2, i = 0;
	
	do
	{char *pt = &postfix[i];
		//運算元 
		if(*pt >= '0' && *pt <='9'){
			Push(*pt - '0');
		}
		
		//運算子 
		else{
			num2 = Pop();
			num1 = Pop();
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
					break;
			} 
		}
		i++;
	}while(postfix[i] != '\0');
	cout << Pop();
}

int main(int argc, char *argv[])
{
   char itemset[20];
   scanf("%s", itemset);
   Transfer(itemset);
}
