ListNode* reverse(ListNode* A) {
    ListNode* curr = A, *prev = 0;
    while(curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int Solution::lPalin(ListNode* A) {
    ListNode *first = A, *second = A, *prev = 0;
    while(first && first->next) {
        first = first->next->next;
        prev = second;
        second = second->next;
    }
    if(prev) prev->next = 0;
    second = reverse(second);
    first = A;
    while(first && second) {
        if(first->val != second->val)
            return 0;
        first = first->next;
        second = second->next;
    }
    return 1;
}

