#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};
// Head and tail pointers of the LinkedList
ListNode* head, *tail; 

// Function to print the LinkedList
void PrintList(ListNode* head) {
    ListNode* curr = head;
    for (; curr != nullptr; curr = curr->next)
        cout << curr->val << "-->";
    cout << "null" << endl;
}

// Function to insert a node at the end of the LinkedList
void InsertatLast(int value) {
    ListNode* newnode = new ListNode(value);
    if (head == nullptr)
        head = newnode, tail = newnode;
    else
        tail = tail->next = newnode;
}

// Function to segregate even and odd nodes in the LinkedList
ListNode* SegregatetoOddEVen() {
    // Creating dummy heads and tails for even and odd lists
    ListNode* oddHead = new ListNode(-1), *oddTail = oddHead;
    ListNode* evenHead = new ListNode(-1), *evenTail = evenHead;

    // Current pointer for traversal
    ListNode* curr = head, *temp;

    while (curr) {
        // Detach current node from the list
        temp = curr;
        curr = curr->next;
        temp->next = nullptr;

        // Append to odd list if value is odd
        if (temp->val & 1) {
            oddTail->next = temp;
            oddTail = temp;
        }
        // Append to even list if value is even
        else {
            evenTail->next = temp;
            evenTail = temp;
        }
    }

    // Connect even list with odd list
    evenTail->next = oddHead->next;

    // Return head of the new rearranged list
    return evenHead->next;
}

int main() {
    // Inserting elements into the LinkedList
    InsertatLast(1);
    InsertatLast(2);
    InsertatLast(3);
    InsertatLast(4);

    // Printing initial LinkedList
    cout << "Initial LinkedList : " << endl;
    PrintList(head);

    // Segregating even and odd nodes
    ListNode* newHead = SegregatetoOddEVen();

    // Printing modified LinkedList
    cout << "LinkedList After Segregration " << endl;
    PrintList(newHead);

    return 0;
}
