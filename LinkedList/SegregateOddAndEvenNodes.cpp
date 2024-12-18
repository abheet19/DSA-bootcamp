#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Input: head -> 1 -> 3 -> 4 -> 2 -> 5 -> 6
// Output: head -> 1 -> 4 -> 3 -> 2 -> 6
// Explanation: The nodes with odd indices are 1, 3, 5 and the ones with even indices are 2, 4.
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    { // Check if list is empty or has only one node
        if (!head or !head->next)
            return head;
        // To store values
        vector<int> list;
        ListNode *temp = head;

        /*Traverse the list, skipping one node, and store values in the vector*/
        while (temp and temp->next)
        {
            list.push_back(temp->val);
            temp = temp->next->next;
        }
        /*If there's an even number of nodes, add the value of the last node*/
        if (temp)
            list.push_back(temp->val);

        // Reset temp
        temp = head;
        temp = head->next;
        /*Traverse the list again, skipping one node and store values in the vector*/

        while (temp and temp->next)
        {
            list.push_back(temp->val);
            temp = temp->next->next;
        }
        /*If there's an odd number of nodes, add the value of the last node*/
        if (temp)
            list.push_back(temp->val);

        // Reset temp
        temp = head;
        int index = 0;

        // Update Node Values

        while (temp)
        {
            temp->val = list[index];
            index++;
            temp = temp->next;
        }
        return head;
    }
    ListNode *oddEvenListInplace(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
        {
            return head;
        }

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = even; // Keep track of the head of the even list

        while (even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead; // Connect the end of the odd list to the beginning of the even list
        return head;
    }
};

void printLL(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Create a linked list with given values
    vector<int> arr = {1, 3, 4, 2, 5, 6};
    ListNode *head = new ListNode(arr[0]);
    head->next = new ListNode(arr[1]);
    head->next->next = new ListNode(arr[2]);
    head->next->next->next = new ListNode(arr[3]);
    head->next->next->next->next = new ListNode(arr[4]);
    head->next->next->next->next->next = new ListNode(arr[5]);

    // Rearrange the list and print it
    Solution solution;
    head = solution.oddEvenList(head);
    printLL(head);

    head = solution.oddEvenListInplace(head);
    printLL(head);

    return 0;
}