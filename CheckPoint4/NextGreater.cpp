vector<int> Solution::nextGreater(vector<int> &A) {
    vector<int> res;
    for(int i = 0; i < A.size(); i++) {
        int nextGreater = -1;
        for(int j = i+1; j < A.size(); j++) {
            if(A[j] > A[i]) {
                nextGreater = A[j];
                break;
            }
        }
        res.push_back(nextGreater);
    }
    return res;
}

