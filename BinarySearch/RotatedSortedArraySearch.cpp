int Solution::search(const vector<int> &A, int B) {
    int s = 0, e = A.size() -1;
    while(s <= e) {
        int m = s + (e-s)/2;
        if(A[m] == B) {
            return m;
        } else if(A[s] < A[m] && B >= A[s] && B < A[m]) {
            e = m-1;
        } else if(A[m] < A[e] && B > A[m] && B <= A[e]) {
            s = m+1;
        } else if(A[s] > A[m]) {
            e = m-1;
        } else {
            s = m+1;
        }
    }
    return -1;
}

