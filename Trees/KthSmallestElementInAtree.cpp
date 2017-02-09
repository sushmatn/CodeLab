int getKth(TreeNode* root, int k, int &curr) {
    if(!root)
        return -1;
        
    int ret = getKth(root->left, k, curr);
    
    if(ret != -1)
        return ret;
        
    curr++;
    if(curr == k) {
        return root->val;
    }
    
    return getKth(root->right, k, curr);
}

int Solution::kthsmallest(TreeNode* root, int k) {
    int curr = 0;
    return getKth(root, k, curr);
}
