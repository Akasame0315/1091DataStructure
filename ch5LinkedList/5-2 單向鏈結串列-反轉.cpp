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
        //�إߪŸ`�I
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

    void Reverse() {
        ListNode* prev = NULL;
        ListNode* current = NULL;
        ListNode* forward = first;

        while (forward->link != NULL) {
            prev = current;
            current = forward;
            forward = forward->link;
            //�N���Ы��V�e�@�Ӹ`�I
            current->link = prev;
        }
        //�N�Ĥ@�ӫ��Ы��V�̫�@�Ӹ`�I �Ϩ䦨���Ĥ@�Ӹ`�I
        forward->link = current;
        first = forward;
    }

    void PrintList() {
        ListNode* p = first;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->link;
        }
        cout << endl;
    }

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