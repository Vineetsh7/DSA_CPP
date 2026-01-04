#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    // Constructor to initialize node value
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Solution {
public:
    // Function to reverse a linked list iteratively
    ListNode* reverseList(ListNode* head) {
        // Initialize previous pointer to NULL
        ListNode* prev = NULL;

        // Start from the head of the list
        ListNode* temp = head;

        // Traverse the list
        while (temp != NULL) {
            // Save the next node
            ListNode* front = temp->next;

            // Reverse the current node's pointer
            temp->next = prev;

            // Move prev to current node
            prev = temp;

            // Move to the next node
            temp = front;
        }

        // Return new head (last node becomes first)
        return prev;
    }
};

// Driver code
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    // Reversing the list
    ListNode* newHead = sol.reverseList(head);

    // Printing the reversed list
    while (newHead != NULL) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}
