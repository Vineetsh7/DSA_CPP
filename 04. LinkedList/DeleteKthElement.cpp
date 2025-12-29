#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

void
print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); ++i)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
Node *removeK(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node *removeElement(Node *head, int el)
{
    if (head == NULL)
        return head;
    if (head->data==el)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

 
    Node *temp = head;
    Node *prev = NULL;
    while (temp != NULL)
    {
    
        if (temp->data==el)
        {
            prev->next = prev->next->next;
            free(temp);
            
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

main()
{
    vector<int> arr{1, 3,2, 4, 5,3, 6};
    Node*head=convertArr2LL(arr);
    head = removeElement(head, 3);
    print(head);
}