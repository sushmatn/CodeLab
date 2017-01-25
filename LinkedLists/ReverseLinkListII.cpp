/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* A) {
    ListNode* prev = 0, *curr = A;
    while(curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
// 1->2->3->4->5   m = 2   n = 4
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = A;
    ListNode* prev = dummy;
    // Find m
    int count = 1;
    ListNode* curr = A;
    while(m != count) {
        prev = curr;
        curr = curr->next;
        count++;
    }
    prev->next = 0;
    ListNode* toReverse = curr;
    // Find n
    while(n != count) {
        curr = curr->next;
        count++;
    }
    ListNode* tail = curr->next;
    curr->next = 0;
    
    ListNode* reversedList = reverse(toReverse);
    prev->next = reversedList;
    toReverse->next = tail;
    
    return dummy->next;
    // curr = 2  prev = 1->0 count = 2
    
}

