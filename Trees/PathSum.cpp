int pathSum(TreeNode* A, int currSum, int B) {
    if(!A)
        return 0;
        
    currSum += A->val;
    if(A->left == 0 && A->right == 0 && currSum == B) {
        return 1;
    }
    if(pathSum(A->left, currSum, B))
        return 1;
    return pathSum(A->right, currSum, B);
}

int Solution::hasPathSum(TreeNode* A, int B) {
    return pathSum(A, 0, B);
}
