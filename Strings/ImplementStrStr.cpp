int Solution::strStr(const string &haystack, const string &needle) {
    int j = 0;
    for(int i = 0; i < haystack.size(); i++) {
        if(haystack[i] == needle[j]) {
            j++;
            if(j == needle.size())
                return i - j + 1;
        } else {
            i = i - j;
            j = 0;
        }
    }
    return -1;
}

