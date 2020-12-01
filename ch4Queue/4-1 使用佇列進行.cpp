#include <iostream>
using namespace std;

class Queue{
public:	
	Queue(){
		front = -1;
		rear = -1;
	}
	
	void Enqueue(int x){
		arr[++rear] = x;
	}
	
	void Dequeue(){
		front++;
	}
	
	void PrintQueue(){
		for(int i = front+1; i <= rear; i++)
			cout << arr[i] << " ";
	}
	
	int arr[10], rear, front;
	
	
};

int main(int argc, char *argv[])
{
    Queue queue;
    int times, input;
    cin >> times;
    for(int i = 0; i < times; i++) {
        cin >> input;
        queue.Enqueue(input);
    }
    cin >> times;
    for(int i = 0; i < times; i++) {
        queue.Dequeue();
    }
    queue.PrintQueue();
}
