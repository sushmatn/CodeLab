int Solution::longestConsecutive(const vector<int> &A) {
    int maxCount = 0;
    unordered_set<int> values;
    for(int i = 0; i < A.size(); i++) {
        values.emplace(A[i]);
    }
    
    while(!values.empty()) {
        auto it = values.begin();
        int val = *it;
        int left = val-1;
        int right = val+1;
        int count = 1;
        values.erase(it);
        
        while(values.find(left) != values.end()) {
            count++;
            values.erase(left);
            left--;
        }
        
        while(values.find(right) != values.end()) {
            count++;
            values.erase(right);
            right++;
        }
        
        maxCount = max(maxCount, count);
    }
    return maxCount;
}

