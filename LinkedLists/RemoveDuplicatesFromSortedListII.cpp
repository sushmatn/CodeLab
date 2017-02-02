ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* resHead = new ListNode(0), *res = resHead, *prev = resHead, *curr = A;
    // 1 1 1
    while(curr) {
        ListNode* next = curr->next;
        if(prev->val != curr->val) {
            if(!next || (next && curr->val != next->val)) {
                res->next = curr;
                res = res->next;
                res->next = 0;
            }
        }
        prev = curr;
        curr = next;
    }
    return resHead->next;
}
