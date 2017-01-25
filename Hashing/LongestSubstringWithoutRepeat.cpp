int Solution::lengthOfLongestSubstring(string A) {
    int start = 0, maxLen = 0;
    unordered_map<char,int> chars;
    for(int i = 0; i < A.size(); i++) {
        if(chars.find(A[i]) == chars.end()) {
            chars[A[i]] = i;
            int len = i - start + 1;
            maxLen = max(len, maxLen);
        } else {
            int idx = chars[A[i]];
            while(start <= idx) {
                chars.erase(A[start++]);
            }
            chars[A[i]] = i;
        }
    }
    return maxLen;
}

