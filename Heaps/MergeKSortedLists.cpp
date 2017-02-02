/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Compare {
    public:
    bool operator() (ListNode* A, ListNode* B) {
        return A->val > B->val;
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    ListNode* resHead = new ListNode(0), *res = resHead;
    priority_queue< ListNode*, vector<ListNode*>, Compare> q;
    for(int i = 0; i < A.size(); i++) {
        q.push(A[i]);
    }
    
    while(!q.empty()) {
        ListNode* node = q.top();
        q.pop();
        if(node->next)
            q.push(node->next);
        res->next = node;
        res = res->next;
    }
    return resHead->next;
}

