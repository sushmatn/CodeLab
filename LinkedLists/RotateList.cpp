/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

int getLength(ListNode *A) {
    int count = 0;
    while(A) {
        count++;
        A = A->next;
    }
    return count;
}

ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(!A || !A->next)
        return A;
        
    int len  = getLength(A);
    B = B % len;
    
    if(B == 0)
        return A;
        
    ListNode* first = A, *second = A, *prev = 0;
    int count = 0;
    while(first) {
        first = first->next;
        count++;
        if(count > B) {
            prev = second;
            second = second->next;
        }
    }
    if(prev) {
        prev->next = 0;
        second = reverse(second);
    } else {
        second = 0;
    }

    first = reverse(A);
    
    ListNode* curr = first;
    prev = 0;
    while(curr) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = second;
    first = reverse(first);
    return first;
}

