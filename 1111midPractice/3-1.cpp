#include <iostream>
using namespace std;

class Stack{
	public:	
		Stack(){
			capacity = 10;
			top = -1;
		}
		
		void Push(int x){
			array[++top] = x;
		}
		
		void Pop(){
			array[top--];
		}
		
		int PrintStack(){
			for(int i = top; i >= 0; i--)
				cout << array[i] << " "; 
		}
	
	int capacity, top;
	int array[10] = {};
	
};

int main(int argc, char *argv[])
{
    Stack stack;
    int times, input;
    cin >> times;
    for(int i = 0; i < times; i++) {
        cin >> input;
        stack.Push(input);
    }
    cin >> times;
    for(int i = 0; i < times; i++) {
        stack.Pop();
    }
    stack.PrintStack();
}
