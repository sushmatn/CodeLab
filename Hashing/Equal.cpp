bool isGreater(vector<int> &A, vector<int> &B) {
    for(int i = 0; i < A.size(); i++) {
        if(A[i] > B[i])
            return true;
        else if(A[i] < B[i])
            return false;
    }    
    return false;
}

vector<int> Solution::equal(vector<int> &A) {
    vector<int> res;
    unordered_map<long, vector<int> > sets;
    for(int i = 0; i < A.size(); i++) {
        for(int j = i+1; j < A.size(); j++) {
            int sum = A[i] + A[j];
            if(sets.find(sum) != sets.end()) {
                if(sets[sum][0] != i && sets[sum][0] != j && sets[sum][1] != i && sets[sum][1] != j) {
                    vector<int> temp = {sets[sum][0], sets[sum][1], i, j};
                    if(res.empty() || isGreater(res, temp)) {
                        res = temp;
                    }
                }
            } else {
                sets[sum] = {i, j};
            }
        }
    }
    return res;
}

