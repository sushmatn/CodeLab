vector<int> Solution::dNums(vector<int> &A, int B) {
    vector<int> res;
    unordered_map<int, int> numCount;
    for(int i =0; i < A.size(); i++) {
        numCount[A[i]]++;
        if(i >= B) {
            numCount[A[i-B]]--;
            if(numCount[A[i-B]] == 0)
                numCount.erase(A[i-B]);
        }
        if(i >= B-1) {
            res.push_back(numCount.size());
        }
    }
    return res;
}

