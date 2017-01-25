string Solution::addBinary(string A, string B) {
    
    int i = A.size() -1;
    int j = B.size() -1;
    int carry = 0;
    string res;
    while( i >=0 || j >= 0 || carry) {
        int val1 = i >= 0 ? A[i] - '0' : 0;
        int val2 = j >= 0 ? B[j] - '0' : 0;
        int v = val1 + val2 + carry;
        res = (v % 2 ? '1' : '0') + res;
        carry = v/2;
        if(i >= 0) i--;
        if(j >= 0) j--;
    }
    return res;
}

