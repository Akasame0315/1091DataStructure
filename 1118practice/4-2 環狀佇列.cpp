#include <iostream>
using namespace std;

class Queue{
public:	
	Queue(){
		front = 0;
		rear = 0;
	}
	
	void Enqueue(int x){
		rear = (rear + 1)%10;
		arr[rear] = x;
	}
	
	void Dequeue(){
		front = (front + 1)%10; 
	}
	
	
	void PrintQueue(){
		if(front >= rear){
			for(int i = front+1; i <= rear+10; i++)
			cout << arr[i%10] << " ";
			
		cout << "rear:" << rear << " ";
		cout << "front:" << front;
		}
		
		else{
			for(int i = front+1; i <= rear; i++)
			cout << arr[i] << " ";
			
		cout << "rear:" << rear << " ";
		cout << "front:" << front;
		}
	}
	
	int arr[10], rear, front;
	
	
};

int main(int argc, char *argv[])
{
    Queue queue;
    int times, input;
    for(int i = 0; i < 2; i++) {
    	cin >> times;
	    for(int j = 0; j < times; j++) {
	        cin >> input;
	        queue.Enqueue(input);
	    }
	    cin >> times;
	    for(int j = 0; j < times; j++) {
	        queue.Dequeue();
	    }
	}
    queue.PrintQueue();
}
