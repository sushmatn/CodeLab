/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    if(!A)
        return 0;
    if(!A->left)
        A->right = flatten(A->right);
    else {
        TreeNode* left = flatten(A->left);
        TreeNode* right = flatten(A->right);
        A->left = 0;
        A->right = left;
        while(left->right) {
            left = left->right;
        }
        left->right = right;
    }
    return A;
}

