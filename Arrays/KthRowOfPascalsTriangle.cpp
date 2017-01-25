vector<int> Solution::getRow(int A) {
    vector<int> prev;
    for(int i = 0; i <= A; i++) {
        vector<int> curr;
        for(int j = 0; j <= i; j++) {
            if(j == 0 || j == i)
                curr.push_back(1);
            else {
                curr.push_back(prev[j] + prev[j-1]);
            }
        }
        prev = curr;
    }
    return prev;
}

