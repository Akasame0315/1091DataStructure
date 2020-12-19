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
        ListNode* temp = new ListNode(x);
        if (first == 0) {
            first = temp;
        }
        else {
            temp->link = first;
            first = temp;
        }
    }
    void InsertLast(int x) {
        ListNode* temp = new ListNode(x);
        if (first == 0) {
            first = temp;
        }
        else {
            ListNode* start = first;
            while (start->link != NULL) {
                start = start->link;
            }
            start->link = temp;
            last = temp;

        }
    }
    int DeleteFirst() {
        ListNode* temp = first;
        first = temp->link;
        return temp->data;
    }
    int DeleteLast() {
        ListNode* start = first;
        while (start->link->link != NULL) {
            start = start->link;
        }
        int x = start->link->data;
        start->link = NULL;
        return x;
    }

    void Reverse() {
        ListNode* prev = NULL;
        ListNode* current = NULL;
        ListNode* forward = first;
        while (forward->link != NULL) {
            prev = current;
            current = forward;
            forward = forward->link;
            current->link = prev;
        }
        forward->link = current;
        first = forward;
    }

    void PrintList() {
        ListNode* start = first;
        while (start != NULL) {
            cout << start->data << " ";
            start = start->link;
        }
        cout << endl;
    }

private:
    ListNode* first;
    ListNode* last;
};

int main(int argc, char* argv[])
{
    LinkedList list;
    int times, input;
    for (cin >> times; times > 0; times--) { cin >> input; list.InsertFirst(input); }
    list.PrintList();
    list.Reverse();
    list.PrintList();
}