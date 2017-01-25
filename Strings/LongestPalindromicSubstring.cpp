string expand(string A, int s, int e) {
    while(s >= 0 && e < A.size() && A[s] == A[e]) {
        s--; e++;
    }
    return A.substr(s+1, e - (s+1));
}
string Solution::longestPalindrome(string A) {
    string longest;
    for(int i = 0; i < A.size(); i++) {
        string temp = expand(A, i, i);
        if(temp.size() > longest.size())
            longest = temp;
        if(i != A.size() -1) {
            temp = expand(A, i, i+1);
            if(temp.size() > longest.size())
            longest = temp;
        }
    }
    return longest;
}

