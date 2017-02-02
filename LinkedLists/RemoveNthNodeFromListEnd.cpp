ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(!A)
        return A;
        
    ListNode* first = A, *second = A, *prev = 0;
    int count = 0;
    while(first) {
        count++;
        first = first->next;
        if(count > B) {
            prev = second;
            second = second->next;
        }
    }
    if(prev) {
        prev->next = second->next;
    } else if(count > 0) {
        A = A->next;
    }
    return A;
}
