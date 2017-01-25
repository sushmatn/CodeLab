int compare(string A, string B) {
    return A + B > B + A;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> nums;
    for(int i = 0; i < A.size(); i++) {
        nums.push_back(to_string(A[i]));
    }
    sort(nums.begin(), nums.end(), compare);
    string res;
    for(int i = 0; i < nums.size(); i++) {
        res += nums[i];
    }
    int i = 0;
    while(res[i] == '0' && i < res.size() -1)
        i++;
    if(i > 0)
        res = res.substr(i);
    return res;
}

