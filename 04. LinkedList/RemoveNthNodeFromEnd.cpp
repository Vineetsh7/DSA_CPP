#include <bits/stdc++.h>
using namespace std;

// Class representing a node in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor for Node with data and next node
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor for Node with only data (next = nullptr)
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Class to hold the solution logic
class Solution {
public:
    // Function to print the linked list
    void printLL(Node* head) {
        while (head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
    }

    // Function to delete the Nth node from the end 
    // using the optimized two-pointer method
    Node* deleteNthNodeFromEnd(Node* head, int N) {
        // Create a dummy node before head to handle edge cases
        Node* dummy = new Node(0, head);

        // Initialize slow and fast pointers at dummy
        Node* slow = dummy;
        Node* fast = dummy;

        // Move fast pointer N+1 steps ahead to create a gap
        for (int i = 0; i <= N; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Slow is now at node before target → delete target node
        slow->next = slow->next->next;

        // Return updated head
        return dummy->next;
    }
};

// Main driver code
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;

    // Create linked list manually
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    // Create Solution object
    Solution sol;

    // Delete the Nth node from the end
    head = sol.deleteNthNodeFromEnd(head, N);

    // Print the modified linked list
    sol.printLL(head);
}
