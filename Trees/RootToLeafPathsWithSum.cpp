/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void getPathSum(vector<vector<int> > &res, TreeNode* A, vector<int> &currPath, int currSum, int sum) {
    if(!A)
        return;
    
    currPath.push_back(A->val);
    currSum += A->val;
    if(!A->left && !A->right) {
        if(currSum == sum) {
            res.push_back(currPath);
        }
    }
    if(A->left)
        getPathSum(res, A->left, currPath, currSum, sum);
    if(A->right)
        getPathSum(res, A->right, currPath, currSum, sum);
    currPath.pop_back();
}

vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    vector<vector<int> > res;
    vector<int> currPath;
    getPathSum(res, root, currPath, 0, sum);
    return res;
}

