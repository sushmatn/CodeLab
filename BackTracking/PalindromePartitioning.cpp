bool isPalin(string S) {
    int s = 0, e = S.size() -1;
    while(s <= e) {
        if(S[s] != S[e])
            return false;
        s++; e--;
    }
    return true;
}

void part(vector<vector<string> >&res, string A, int idx, vector<string> &curr) {
    if(idx >= A.size()) {
        res.push_back(curr);
        return;
    }
    for(int len = 1; len + idx <= A.size(); len++) {
        string temp = A.substr(idx, len);
        if(len == 1 || isPalin(temp)) {
            curr.push_back(temp);
            part(res, A, idx+len, curr);
            curr.pop_back(); 
        }
    }
    
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string> > res; vector<string> curr;
    part(res, A, 0, curr);
    return res;
}

