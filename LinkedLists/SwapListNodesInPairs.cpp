/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode*curr = A, *dummy = new ListNode(0), *prev = dummy; 
    prev->next = A;

    while(curr && curr->next) {
        ListNode* next = curr->next->next;
        prev->next = curr->next;
        curr->next->next = curr;
        curr->next = next;
        prev = curr;
        curr = next;
    }
    return dummy->next;
}

