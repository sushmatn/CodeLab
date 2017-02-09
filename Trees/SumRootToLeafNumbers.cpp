/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void getNum(TreeNode* A, int currSum, int &totalSum) {
    if(!A)
        return;

    currSum = (currSum*10 + A->val) % 1003;
    
    if(A->left == 0 && A->right == 0) {
        totalSum = (totalSum + currSum) % 1003;
    }
    
    getNum(A->left, currSum, totalSum);
    getNum(A->right, currSum, totalSum);
}

int Solution::sumNumbers(TreeNode* A) {
    int totalSum = 0;
    getNum(A, 0, totalSum);
    return totalSum;
}

