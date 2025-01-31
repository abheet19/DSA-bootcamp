package main

import "fmt"

type ListNode struct {
    Val int
    Next *ListNode
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, left int, right int) *ListNode {
    if head == nil || left == right {
        return head     // Nothing to reverse for empty list or same left/right
    }
    dummy := &ListNode{Next: head} // Dummy node to handle case where left = 1
    prefixEnd := dummy             // Node before the start of the reversal
    current :=head                
    position :=1

    for position < left {       // 1. Traverse to find the node before the start of the reversal (prefixEnd)
        prefixEnd = current     
        current = current.Next
        position++
    }
    reverseStart := current      // Node at position 'left', start of reversal

    // 2. Initialize for reversal within the range

    var prev *ListNode = nil
    currentReversal := current // Start reversal from 'reverseStart'

    // 3. Reverse within the range [left, right]
    for position <=right && currentReversal!= nil{
        next := currentReversal.Next
        currentReversal.Next =prev
        prev=currentReversal
        currentReversal=next
        position++
    }
    prefixEnd.Next = prev  // Connect prefixEnd to the new head of the reversed segment
    reverseStart.Next = currentReversal // Connect the tail of the reversed segment to the node after the reversed segment

    return dummy.Next
}

// Helper function to create a linked list
func createLinkedList(values []int) *ListNode {
    if len(values) == 0 {
        return nil
    }
    head := &ListNode{Val: values[0]}
    current := head
    for i := 1; i < len(values); i++ {
        current.Next = &ListNode{Val: values[i]}
        current = current.Next
    }
    return head
}

// Helper function to print the linked list
func printList(head *ListNode) {
    current := head
    for current != nil {
        fmt.Printf("%d -> ", current.Val)
        current = current.Next
    }
    fmt.Println("nil")
}

func main() {
    // Test case
    values := []int{1, 2, 3, 4, 5}
    head := createLinkedList(values)
    
    fmt.Println("Original list:")
    printList(head)
    
    // Reverse nodes from position 2 to 4
    result := reverseBetween(head, 2, 4)
    
    fmt.Println("After reversing from position 2 to 4:")
    printList(result)
}