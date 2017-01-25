int Solution::lengthOfLastWord(const string &A) {
    if(A.empty())
        return 0;
    int i = A.size() -1;
    while(A[i] == ' ')
        i--;
        
    int start = i;
    while( i >= 0 && !isspace(A[i]))
        i--;
    return start - i;
}

