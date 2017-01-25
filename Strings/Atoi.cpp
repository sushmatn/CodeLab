int Solution::atoi(const string &A) {
    long res = 0;
    int i = 0;
    
    // Eliminate space
    while(A[i] == ' ')
        i++;
    
    bool isNeg = false;
    if(A[i] == '-') {
        isNeg = true;
        i++;
    }
    else if(A[i] == '+')
        i++;
    
    while(A[i] == '0')
        i++;
        
    while(i < A.size()) {
        if(!isdigit(A[i]))
            break;
        res = res * 10 + A[i] - '0';
        if(res >= INT_MAX || res <= INT_MIN)
            break;
        i++;
    }
    
    if(isNeg)
        res = -res;
    if(res >= INT_MAX)
        return INT_MAX;
    if(res <= INT_MIN)
        return INT_MIN;
    
    return res;
}

