string Solution::longestCommonPrefix(vector<string> &A) {
    string res;
    if(A.empty())
        return 0;
    if(A.size() == 1)
        return A[0];
    
    int len = 0;
    string first = A[0];
    for(int i = 0; i < first.size(); i++) {
        for(int j = 1; j < A.size(); j++) {
            if(first[i] != A[j][i])
                return first.substr(0, len);
        }
        len++;
    }
    return first;
}

