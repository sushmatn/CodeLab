/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* root) {
    ListNode* prev = 0;
    while(root) {
        ListNode* next = root->next;
        root->next = prev;
        prev = root;
        root = next;
    }
    return prev;
}

ListNode* Solution::subtract(ListNode* A) {
    if(!A || !A->next)
        return A;
        
    // Separate the list into 2 halves
    ListNode* fast = A, *slow = A, *prev = 0;
    while(fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    if(prev) prev->next = 0;
    
    // Reverse the second half
    ListNode* second = reverse(slow);
    ListNode* secHead = second;
    ListNode* first = A;
    // Perform subtraction
    while(first && second) {
        first->val = second->val - first->val;
        first = first->next;
        second = second->next;
    }
    first = A;
    while(first->next) {
        first = first->next;
    }
    // Reverse the second half and append to the first half
    first->next = reverse(secHead);
    return A;
}

