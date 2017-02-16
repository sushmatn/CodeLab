void combSum(vector<vector<int> > &res, vector<int> &A, int B, int index, int currSum, vector<int> &curr) {
    if(currSum > B)
        return;
        
    if(currSum == B) {
        res.push_back(curr);
        return;
    }
    for(int i = index; i < A.size(); i++) {
        if(i > index && A[i] == A[i-1])
            continue;
        curr.push_back(A[i]);
        combSum(res, A, B, i, currSum + A[i], curr);
        curr.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    vector<vector<int> > res;
    vector<int> curr;
    combSum(res, A, B, 0, 0, curr);
    return res;
}

