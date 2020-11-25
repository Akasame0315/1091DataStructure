#include <iostream>
using namespace std;

class Queue{
public:	
	Queue(){
		front = 0;
		rear = 0;
	}
	
	void Enqueue(int x){
		arr[rear++] = x;
		rear %= 10;
	}
	
	void Dequeue(){
		front++;
		front %= 10; 
	}
	
	void BackEnqueue(int x){
		front = (front+9)%10;
		arr[front] = x;
	}
	
	void BackDequeue(){
		rear = (rear+9)%10;
	}
	
	void PrintQueue(){
		if(front >= rear){
			for(int i = front; i < rear+10; i++)
			cout << arr[i%10] << " ";
			
		cout << "rear:" << rear << " ";
		cout << "front:" << front;
		}
		
		else{
			for(int i = front; i < rear; i++)
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
	cin >> times;
    for(int j = 0; j < times; j++) {
        cin >> input;
        queue.Enqueue(input);
    }
    cin >> times;
    for(int j = 0; j < times; j++) {
        queue.Dequeue();
    }
    cin >> times;
    for(int j = 0; j < times; j++) {
        cin >> input;
        queue.BackEnqueue(input);
    }
    cin >> times;
    for(int j = 0; j < times; j++) {
        queue.BackDequeue();
    }
    queue.PrintQueue();
}
