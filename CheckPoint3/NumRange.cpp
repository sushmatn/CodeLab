int Solution::numRange(vector<int> &A, int B, int C) {
    if(A.empty())
        return 0;
    int sum = 0, start = 0, res = 0;
    for(int i = 0; i < A.size(); i++) {
        int j = i; sum = 0;
        while(j < A.size()) {
            sum += A[j];
            if(sum >= B && sum <= C) 
                res++;
            if(sum > C)
                break;
            j++;
        }
    }
    return res;
}

