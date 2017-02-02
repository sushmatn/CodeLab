ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* resHead = new ListNode(0), *prev = resHead, *curr = A;
    prev->next = A;
    while(curr) {
        if(prev->val == curr->val) {
            prev->next = curr->next;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }
    return resHead->next;
}
