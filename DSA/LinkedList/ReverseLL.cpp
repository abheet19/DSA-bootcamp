#include <bits/stdc++.h>
using namespace std;

// Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // Time complexity: O(n)
    // Space complexity: O(n)
    ListNode *reverseListIterative(ListNode *head)
    {
        stack<ListNode *> st;
        ListNode *temp = head;

        // Push all the nodes of the linked list into the stack
        while (temp != nullptr)
        {
            st.push(temp);
            temp = temp->next;
        }

        // Pop the nodes from the stack and create the reversed linked list
        temp = st.top();
        head = temp;
        st.pop();
        while (!st.empty())
        {
            temp->next = st.top();
            st.pop();
            temp = temp->next;
        }
        temp->next = nullptr;
        return head;
    }
    // Time complexity: O(n)
    // Space complexity: O(1)
    ListNode *reverseListIterativeOptimal(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = nullptr;
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    // Time complexity: O(n)
    // Space complexity: O(n)
    ListNode *reverseListRecursive(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *newHead = reverseListRecursive(head->next);

        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
};

void printLinkedList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    // Create a linked list with
    // Values 1, 3, 2, and 4
    ListNode *head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Solution instance
    Solution sol;
    // Reverse the linked list
    head = sol.reverseList(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}