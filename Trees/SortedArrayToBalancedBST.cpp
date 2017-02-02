TreeNode* sortedToBSTH(const vector<int> &A, int start, int end) {
    if(start > end)
        return 0;
    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(A[mid]);
    root->left = sortedToBSTH(A, start, mid-1);
    root->right = sortedToBSTH(A, mid+1, end);
    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return sortedToBSTH(A, 0, A.size() -1);
}
