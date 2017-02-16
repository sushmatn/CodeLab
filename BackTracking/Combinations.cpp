void comb(vector<vector<int> >&res, vector<int> &currSoln, int n, int k, int idx) {
    if(currSoln.size() == k) {
        res.push_back(currSoln);
        return;
    }
    if(idx > n) {
        return;
    }
    for(int i = idx; i <= n; i++) {
        currSoln.push_back(i);
        comb(res, currSoln, n, k, i+1);
        currSoln.pop_back();
    }
}
vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int> > res;    
    vector<int> currSoln;
    comb(res, currSoln, n, k, 1);
    return res;
}

