/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> res;
    if(!A)
        return res;
        
    stack<TreeNode*> stk;
    stk.push(A);
    
    while(!stk.empty()) {
        TreeNode* curr = stk.top();
        if(curr->left) {
            stk.push(curr->left);
            curr->left = 0;
        } else {
            stk.pop();
            res.push_back(curr->val);
            if(curr->right)
                stk.push(curr->right);
        }
    }
    return res;
}

