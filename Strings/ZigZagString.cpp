string Solution::convert(string A, int B) {
    string res;
    if(B == 1 || B > A.size())
        return A;
    for(int i = 0; i < B; i++) {
        int j = i;
        res += A[j];
        while(j < A.size()) {
            // Go down
            int downCnt = 2 * abs(i - (B - 1));
            if(downCnt > 0) {
                j+= downCnt;
                if(j < A.size())
                    res += A[j];
            }
                
            // Go up
            int upCnt = 2 * abs(i-0);
            if(upCnt > 0) {
                j+= upCnt;
                if(j < A.size())
                    res += A[j];
            }
        }
    }
    return res;
}

