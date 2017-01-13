void permuteH(vector<vector<int> >& res, vector<int> &A, vector<int> &curr, bool avail[]) {
    if(curr.size() == A.size()) {
        res.push_back(curr);
        return;
    }    
    int lastIdx = -1;
    for(int i = 0; i < A.size(); i++) {
        if(!avail[i]) 
            continue;
        if(lastIdx > -1 && A[i] == A[lastIdx])
            continue;
        avail[i] = 0;
        curr.push_back(A[i]);
        permuteH(res, A, curr, avail);
        curr.pop_back();
        avail[i] = 1;
        lastIdx = i;
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int> > res;
    bool avail[A.size()];
    std::fill_n(avail, A.size(), 1);
    sort(A.begin(), A.end());
    vector<int> curr;
    permuteH(res, A, curr, avail);
    return res;
}

