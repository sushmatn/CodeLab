int Solution::isPalindrome(string A) {
    int i = 0, j = A.size() -1;
    while(i <= j) {
        while( i <= j && !isalnum(A[i]))
            i++;
        if( i <= j && !isalnum(A[j]))
            j--;
        if(i <= j && isalnum(A[i]) && isalnum(A[j])) {
            if(tolower(A[i]) != tolower(A[j]))
                return 0;
            i++; j--;
        }
    }
    return 1;
}

