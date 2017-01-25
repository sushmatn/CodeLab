/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* dummy = new ListNode(0);
    ListNode* res = dummy;
    while(A && B) {
        if(A->val < B->val) {
            res->next = A;
            A = A->next;
        } else {
            res->next = B;
            B = B->next;
        }
        res = res->next;
        res->next = 0;
    }
    while(A) {
        res->next = A;
        res = res->next;
        A = A->next;
    }
    while(B) {
        res->next = B;
        res = res->next;
        B = B->next;
    }
    return dummy->next;
}

