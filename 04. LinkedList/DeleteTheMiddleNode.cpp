#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in the linked list
class Node {
public:
    // Data stored in the node
    int data;

    // Pointer to the next node
    Node* next;

    // Constructor with data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to delete the middle node using slow and fast pointer
Node* deleteMiddle(Node* head) {
    // If list has only one node, delete it
    if (head == nullptr || head->next == nullptr) {
        delete head;
        return nullptr;
    }

    // Initialize slow pointer to head
    Node* slow = head;

    // Initialize fast pointer two steps ahead
    Node* fast = head->next->next;

    // Traverse until fast reaches end
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Pointer to middle node
    Node* middle = slow->next;

    // Bypass the middle node
    slow->next = slow->next->next;

    // Delete middle node
    delete middle;

    // Return head of updated list
    return head;
}

// Function to print linked list
void printLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver function
int main() {
    // Creating linked list 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Printing original list
    cout << "Original Linked List: ";
    printLL(head);

    // Deleting middle node
    head = deleteMiddle(head);

    // Printing updated list
    cout << "Updated Linked List: ";
    printLL(head);

    return 0;
}
