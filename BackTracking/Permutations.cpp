void permuteH(vector<vector<int> >& res, vector<int> &A, vector<int> &currSoln, vector<int> &avail) {
    if(currSoln.size() == A.size()) {
        res.push_back(currSoln);
        return;
    }
    for(int i = 0; i < A.size(); i++) {
        if(!avail[i])
            continue;
        avail[i] = 0;
        currSoln.push_back(A[i]);
        permuteH(res, A, currSoln, avail);
        currSoln.pop_back();
        avail[i] = 1;
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > res;
    vector<int> currSoln;
    vector<int> avail(A.size(), 1);
    permuteH(res, A, currSoln, avail);
    return res;
}

