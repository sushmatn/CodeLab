/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int getHeight(TreeNode* A) {
    if(!A)
        return 0;
    int left = getHeight(A->left);
    int right = getHeight(A->right);
    
    if(left == -1 || right == -1)
        return -1;
        
    if(abs(left - right) > 1)
        return -1;
    return 1 + max(left, right);
}

int Solution::isBalanced(TreeNode* A) {
    if(!A)
        return 1;
    int height = getHeight(A);
    return height != -1;
}

