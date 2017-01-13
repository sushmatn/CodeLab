void getMinMax(const vector<int> &A, int &minV, int &maxV) {
    for(int i = 0; i < A.size(); i++) {
        minV = min(A[i], minV);
        maxV = max(A[i], maxV);
    }
}

int Solution::kthsmallest(const vector<int> &A, int k) {
    int N = A.size();
    if(k > N)
        return -1;
    int lo = INT_MAX, hi = INT_MIN;
    getMinMax(A, lo, hi);
    
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        int less = 0, eq = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] >= lo && A[i] < mid)
                less ++;
            else if(A[i] == mid)
                eq ++;
        }
        
        // Eliminate right half
        if(less >= k) {
            hi = mid - 1;
            continue;
        }
        // Eliminate left half
        else if(less < k) {
            k-= less;
            lo = mid;
        }
        
        if(eq >= k)
            return mid;
        else {
            k-= eq;
            lo = mid+1;
        }
    }
    
    return -1;
}

