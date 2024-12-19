#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0); // Dummy node to act as the starting point of the result list
        ListNode *current = dummy;         // current pointer to build the result list
        int carry = 0;

        // Iterate while there are nodes in l1 or l2 or there's a carry to process
        while (l1 || l2 || carry)
        {
            int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = sum / 10;
            current->next = new ListNode(sum % 10); // Create a new node with the digit value and attach it to the result list
            current = current->next;                // Move to the next position in the result list
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        // Return the result list skipping the dummy node
        return dummy->next;
    }
};

void printList(ListNode *head)
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

    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3))); // l1: 2 -> 4 -> 3 -> NULL  (Represents 342)
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4))); // l2: 5 -> 6 -> 4 -> NULL  (Represents 465)

    Solution solution;
    ListNode *result = solution.addTwoNumbers(l1, l2); // result: 7 -> 0 -> 8 ->NULL

    printList(result);
    return 0;
}