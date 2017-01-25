vector<int> Solution::twoSum(const vector<int> &A, int B) {
    vector<int> res;
    unordered_map<int, int> nums;
    for(int i = 0; i < A.size(); i++) {
        if(nums.find(B-A[i]) != nums.end()) {
            res.push_back(nums[B-A[i]]+1);
            res.push_back(i+1);
            return res;
        }
        if(nums.find(A[i]) == nums.end())
            nums[A[i]] = i;
    }
    return res;
}

