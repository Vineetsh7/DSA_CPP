#include <bits/stdc++.h>
using namespace std;
        
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       //Initialize a dummy node as a new node
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        //Carry will be carried to the next new node created
        int carry = 0;
        //Iterate till the end of both the lists
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            //Repeat the same process for l2 as l1
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            //Carry gets added to sum in the node (carry=sum/10)
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
    }
};
ListNode* createList(vector<int> arr) {
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < arr.size(); i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Helper to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector num1 = {2, 4, 3}; // represents 342
    vector num2 = {5, 6, 4}; // represents 465
    ListNode* l1 = createList(num1);
    ListNode* l2 = createList(num2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);
    printList(result); // Output: 7 -> 0 -> 8
    return 0;
}
