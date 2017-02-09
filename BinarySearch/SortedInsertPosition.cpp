int Solution::searchInsert(vector<int> &A, int B) {
    int s = 0, e = A.size() -1;
    while(s <= e) {
        int m = s + (e-s)/2;
        if(A[m] == B)
            return m;
        else if(A[m] > B) {
            e = m-1;
        } else {
            s = m+1;
        }
    }
    return s;
}

