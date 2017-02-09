/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* lcaN(TreeNode* root, int val1, int val2, int &firstFound, int &secondFound) {
    if(!root)
        return 0;
        
    TreeNode* left = lcaN(root->left, val1, val2, firstFound, secondFound);
    TreeNode* right = lcaN(root->right, val1, val2, firstFound, secondFound);
    if(left && right) {
        return root;
    }
    if(root->val == val1 || root->val == val2) {
        if(root->val == val1) { 
            firstFound = 1;
        }
        if(root->val == val2) {
            secondFound = 1;
        }
        return root;
    }
    return left ? left : right;
}

int Solution::lca(TreeNode* A, int val1, int val2) {
    int firstFound = 0, secondFound =0;
    TreeNode* node = lcaN(A, val1, val2, firstFound, secondFound);
    return node && firstFound && secondFound ? node->val : -1;
}

