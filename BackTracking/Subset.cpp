void getSubsets(vector<vector<int> > &res, vector<int> &A, vector<int> &currSoln, int idx) {
    res.push_back(currSoln);
    
    if(idx == A.size())
        return;
        
    for(int i = idx; i < A.size(); i++) {
        currSoln.push_back(A[i]);
        getSubsets(res, A, currSoln, i+1);
        currSoln.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int> > res;
    vector<int> currSoln;
    sort(A.begin(), A.end());
    getSubsets(res, A, currSoln, 0);
    return res;
}

