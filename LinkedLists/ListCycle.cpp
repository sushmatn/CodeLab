/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* hasCycle(ListNode* A) {
    ListNode* first = A, *second = A;
    while(first && first->next) {
        first = first->next->next;
        second = second->next;
        if(first == second) {
            return second;
        }
    }    
    return 0;
}

ListNode* Solution::detectCycle(ListNode* A) {
    if(!A)
        return A;
        
    if(A->next == A)
        return A;
    
    ListNode* cycleNode = hasCycle(A);
    if(!cycleNode)
        return cycleNode;
    
    // Find the length of the cycle
    ListNode* second = cycleNode->next;
    int count = 1;
    while(second != cycleNode) {
        count++;
        second = second->next;
    }
    //cout << count << " ";
    
    // Move the first pointer by length of the cycle
    ListNode* first = A;
    second = A;
    while(count) {
        first = first->next;
        count--;
    }
    
    while(first != second) {
        first = first->next;
        second = second->next;
    }
    return second;
}

