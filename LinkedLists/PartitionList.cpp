/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* less = new ListNode(0), *lessPtr = less;
    ListNode* more = new ListNode(0), *morePtr = more;
    while(A) {
        ListNode* next = A->next;
        if(A->val < B) {
            lessPtr->next = A;
            lessPtr = lessPtr->next;
            lessPtr->next = 0;
        } else {
            morePtr->next = A;
            morePtr = morePtr->next;
            morePtr->next = 0;
        }
        A = next;
    }
    lessPtr->next = more->next;
    return less->next;
}

