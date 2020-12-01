#include <iostream>
using namespace std;

class ListNode
{
public:
    ListNode(int a) { data = a; link = 0; }
private:
    int data;
    ListNode* link;
    friend class LinkedList;
};

class LinkedList {
public:
    LinkedList() {
        first = 0;
        last = 0;
    }

    void InsertFirst(int x) {
        //建立空節點
        ListNode* p = new ListNode(x);
        p->link = first;
        first = p;
    }

    void InsertLast(int x) {
        ListNode* p = new ListNode(x);
        if (first == 0)
            first = p;

        else {
            ListNode* current = first;
            while (current->link != NULL)
                current = current->link;

            current->link = p;
        }
    }

    int DeleteFirst() {
        first = first->link;
        return first->data;
    }

    int DeleteLast() {
        ListNode* current = first;
        while ((current->link)->link != NULL)
            current = current->link;

        int x = current->data;
        current->link = NULL;
        return x;
    }

    void PrintList() {
        ListNode* p = new ListNode(NULL);
        p = first;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->link;
        }
        cout << endl;
    }

    ListNode* first;
    ListNode* last;
};

class Stack : public LinkedList{
public:
    Stack() {
        
    }

    void Push(int x) {
        InsertLast(x);
    }

    int Pop() {
        return DeleteLast();
    }

    void PrintStack() {
        PrintList();
    }
};

int main(int argc, char* argv[])
{
    Stack stack;
    int times, input;
    for (cin >> times; times > 0; times--) { cin >> input; stack.Push(input); }
    for (cin >> times; times > 0; times--) stack.Pop();
    stack.PrintStack();
}