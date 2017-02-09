TreeNode* Solution::invertTree(TreeNode* root) {
    if(!root)
        return 0;
    TreeNode* temp = invertTree(root->right);
    root->right = invertTree(root->left);
    root->left = temp;
    return root;
}
