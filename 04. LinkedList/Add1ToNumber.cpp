#include <bits/stdc++.h>
using namespace std;

// Node class representing a single digit in the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class having only append and print logic
class LinkedList {
public:
    // Function to insert digit at the end
    Node* append(Node* head, int value) {
        Node* newNode = new Node(value);
        if (!head) {
            return newNode;
        }
        Node* current = head;
        while (current->next)
            current = current->next;
        current->next = newNode;
        return head;
    }

    // Function to print the list
    void printList(Node* head) {
        Node* current = head;
        while (current) {
            cout << current->data;
            current = current->next;
        }
        cout << endl;
    }
};

// Solution class having the addOne logic
class Solution {
public:
    // Recursive function to add one from least significant digit (rightmost node)
    int addOneUtil(Node* node) {
        // Base case: when reaching beyond last node, return carry = 1
        if (!node) return 1;
        
        // Recurse to the end
        int carry = addOneUtil(node->next);  
        int sum = node->data + carry;
        node->data = sum % 10;
        // Return new carry
        return sum / 10;  
    }

    // Function to add one to the number represented by the linked list
    Node* addOne(Node* head) {
        // Perform recursive addition
        int carry = addOneUtil(head);

        // If carry remains after processing the head, create a new head node
        if (carry) {
            Node* newHead = new Node(carry);
            newHead->next = head;
            head = newHead;
        }

        return head;
    }
};

int main() {
    Node* head = nullptr;
    LinkedList ll;
    Solution sol;

    // Example: Number 129 (1 -> 2 -> 9)
    head = ll.append(head, 1);
    head = ll.append(head, 2);
    head = ll.append(head, 9);

    cout << "Original Number: ";
    ll.printList(head);

    head = sol.addOne(head);

    cout << "After Adding One: ";
    ll.printList(head);

    return 0;
}
 