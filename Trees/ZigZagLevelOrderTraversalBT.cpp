/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > res;
    if(!A)
        return res;
    bool rev = false;
    queue<TreeNode*> q;
    q.push(A);
    while(!q.empty()) {
        int sz = q.size();
        vector<int> level;
        for(int i = 0; i < sz; i++) {
            TreeNode* curr = q.front();
            q.pop();
            level.push_back(curr->val);
            if(curr->left) {
                q.push(curr->left);
            }
            if(curr->right) {
                q.push(curr->right);
            }
        }
        if(rev) {
            reverse(level.begin(), level.end());
        }
        rev = !rev;
        res.push_back(level);
    }
    return res;
}

