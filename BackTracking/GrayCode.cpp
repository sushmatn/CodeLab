vector<int> Solution::grayCode(int A) {
    if(A == 0) {
        vector<int> res = {0};
        return res;
    }
    vector<int> res = grayCode(A-1);
    int numToAdd = 1 << A-1;
    for(int i = res.size() -1; i >= 0; i--) {
        res.push_back(numToAdd + res[i]);
    }
    return res;
}

