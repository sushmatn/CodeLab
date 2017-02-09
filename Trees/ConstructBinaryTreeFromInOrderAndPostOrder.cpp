/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findIdx(vector<int> &inorder, int s, int e, int n) {
    for(int i = s; i <= e; i++) {
        if(inorder[i] == n)
            return i;
    }    
    return 0;
} 

TreeNode* build(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe) {
    if(ps > pe)
        return 0;
    TreeNode* root = new TreeNode(postorder[pe]);
    int idx = findIdx(inorder, is, ie, postorder[pe]);
    root->left = build(inorder, is, idx-1, postorder, ps, ps+(idx-is)-1);
    root->right = build(inorder, idx+1, ie, postorder, ps+(idx-is) , pe-1);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    return build(inorder,0, inorder.size()-1, postorder, 0, postorder.size()-1);
}

