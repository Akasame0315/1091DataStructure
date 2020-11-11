#include <iostream>
using namespace std;

class Stack{
    public:
    
    Stack(){
        top = -1;
        capacity = 10;
        array[capacity];
    }  
      
    void Push(int x){
        array[++top] = x;
    }
      
    void Pop(){
        array[top--];
    }
      
    void PrintStack(){
        while(top > -1)
            cout << array[top--] << " ";
    }
      
    int capacity = 10, top = -1;
    int array[10];
        
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
