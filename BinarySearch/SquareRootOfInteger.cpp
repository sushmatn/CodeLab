int Solution::sqrt(int A) {
    if(A == 1)
        return 1;
    
    // The square root will lie between 1 and A/2
    int s = 1, e = A/2, res;
    while(s <= e) {
        int m = s + (e-s)/2;
        if(m <= A/m) { // eg: 11
            s = m+1;
            res = m;
        } else {        // eg: 14
            e = m-1;
        }
    }
    return floor(res);
}

