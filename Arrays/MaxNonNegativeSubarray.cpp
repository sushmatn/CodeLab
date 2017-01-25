int Solution::maxSubArray(const vector<int> &A) {
    if(A.empty())
        return 0;
        
    int maxSum = A[0], sum = A[0];
    for(int i = 1; i < A.size(); i++) {
        sum = max(A[i], sum + A[i]);
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

