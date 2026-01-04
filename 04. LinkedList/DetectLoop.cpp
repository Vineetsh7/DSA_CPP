#include <bits/stdc++.h>
using namespace std;

// Node class represents a linked list node
class Node {
public:
    // Data stored in the node
    int data;

    // Pointer to the next node
    Node* next;

    // Constructor with data and next
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

// Solution class contains the loop detection method
class Solution {
public:
    // Function to detect a loop in the linked list
    bool detectLoop(Node* head) {
        // Initialize a pointer at head
        Node* temp = head;

        // Create a map to keep track of visited nodes
        unordered_map<Node*, int> nodeMap;

        // Traverse the linked list
        while (temp != nullptr) {
            // If node already exists in map, loop detected
            if (nodeMap.find(temp) != nodeMap.end()) {
                return true;
            }
            // Store the current node in the map
            nodeMap[temp] = 1;

            // Move to the next node
            temp = temp->next;
        }

        // If traversal completes, no loop detected
        return false;
    }
};

// Driver function
int main() {
    // Create sample linked list nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Link the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create a loop for testing
    fifth->next = third;

    // Create a Solution object
    Solution obj;

    // Check if loop exists
    if (obj.detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Free allocated memory
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}
