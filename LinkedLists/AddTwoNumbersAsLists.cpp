ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* resHead = new ListNode(0), *res = resHead;
    int carry = 0;
    while(A || B || carry) {
        int val1 = A ? A->val : 0;
        int val2 = B ? B->val : 0;
        res->next = new ListNode((val1 + val2 + carry) % 10);
        res = res->next;
        carry = (val1 + val2 + carry) / 10;
        if(A) A = A->next;
        if(B) B = B->next;
    }
    return resHead->next;
}
