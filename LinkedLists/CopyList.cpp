/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if(!A)
        return A;
    RandomListNode* curr = A;
    while(curr) {
        RandomListNode* next = curr->next;
        curr->next = new RandomListNode(curr->label);
        curr->next->next = next;
        curr = next;
    }
    
    curr = A;
    while(curr) {
        if(curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }
    
    RandomListNode* resHead = new RandomListNode(0), *res = resHead;
    curr = A;

    while(curr) {
        res->next = curr->next;
        res = res->next;
        curr->next = curr->next->next;
        curr = curr->next;
    }
    
    return resHead->next;
}

