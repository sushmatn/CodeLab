/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* root) {
    ListNode* prev;
    while(root) {
        ListNode* next = root->next;
        root->next = prev;
        prev = root;
        root = next;
    }
    return prev;
}
ListNode* Solution::reorderList(ListNode* A) {
    if(!A || !A->next)
        return A;
        
    ListNode* first = A, *second = A, *prev = 0;
    while(first && first->next) {
        first = first->next->next;
        prev = second;
        second = second->next;
    }
    if(prev) prev->next = 0;
    
    first = A; 
    second = reverse(second);
    
    ListNode* resHead = new ListNode(0), *res = resHead;
    while(first && second) {
        res->next = first;
        res = res->next;
        first = first->next;
        
        res->next = second;
        res = res->next;
        second = second->next;
    }
    if(first)
        res->next = first;
    if(second)
        res->next = second;
    
    return resHead->next;
}

