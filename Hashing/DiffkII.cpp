int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_map<int, int> nums;
    for(int i = 0; i < A.size(); i++) {
        int sum = A[i] + B;
        int diff = A[i] - B;
        if(nums.find(sum) != nums.end())
            return 1;
        if(diff > 0 && nums.find(diff) != nums.end())
            return 1;
        nums[A[i]] = i;
    }
    return 0;
}

