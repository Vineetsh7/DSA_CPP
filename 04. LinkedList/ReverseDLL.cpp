#include <bits/stdc++.h>
using namespace std;

// Class representing a Node in a doubly linked list
class Node
{
public:
    // To store value of the node
    int data;
    // Pointer to the next node
    Node *next;
    // Pointer to the previous node
    Node *back;

    // Constructor with data, next, and back references
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor with only data (default next and back to null)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array into a doubly linked list
Node *convertArr2DLL(vector<int> arr)
{
    // Create the head node using first array element
    Node *head = new Node(arr[0]);

    // Maintain a reference to the last node inserted (previous node)
    Node *prev = head;

    // Loop through the remaining array and link nodes
    for (int i = 1; i < arr.size(); i++)
    {
        // Create a new node with current array element
        // Set its back to prev
        Node *temp = new Node(arr[i], nullptr, prev);

        // Link previous node's next to current node
        prev->next = temp;

        // Update prev to current node
        prev = temp;
    }

    // Return the head of the DLL
    return head;
}

// Function to print the doubly linked list
void print(Node *head)
{
    // Traverse from head to end and print each node's data
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to reverse the doubly linked list in-place
Node *reverseDLL(Node *head)
{
    // If list is empty or has one node, nothing to reverse
    if (head == nullptr || head->next == nullptr)
        return head;

    // Pointer to track the current node
    Node *curr = head;

    // Traverse the DLL
    while (curr != nullptr)
    {
        // Swap next and back pointers of current node
        Node *temp = curr->next;
        curr->next = curr->back;
        curr->back = temp;

        // Move to the next node in original order
        head = curr;
        curr = temp;
    }

    // Return new head after full reversal
    return head;
}

// Driver code
int main()
{
    // Sample input array
    vector<int> arr = {10, 20, 30, 40};

    // Convert array to DLL
    Node *head = convertArr2DLL(arr);

    // Reverse the DLL
    head = reverseDLL(head);

    // Print the reversed DLL
    print(head);

    return 0;
}
