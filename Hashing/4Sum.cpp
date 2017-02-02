vector<vector<int> > tSum(vector<int> &A, int start, int B) {
    vector<vector<int> > res;     
    for(int i = start; i < A.size(); i++) {
        if(i > start && A[i] == A[i-1])
            continue;
        int j = i+1, k = A.size() -1;
        while(j < k) {
            int sum = A[i] + A[j] + A[k];
            if(sum == B) {
                res.push_back(vector<int> {A[i], A[j], A[k]});
                j++;
                while( j < k && A[j] == A[j-1])
                    j++;
                k--;
                while( j < k && A[k] == A[k+1])
                    k--;
            } else if(sum < B) {
                j++;
                while( j < k && A[j] == A[j-1])
                    j++;
            } else {
                k--;
                while( j < k && A[k] == A[k+1])
                    k--;
            }
        }
    }
    return res;
}

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    vector<vector<int> > res;  
    sort(A.begin(), A.end());
    for(int i = 0; i < A.size(); i++) {
        if(i > 0 && A[i] == A[i-1])
            continue;
        vector<vector<int> > temp = tSum(A, i+1, B - A[i]);
        if(!temp.empty()) {
            for(int j = 0; j < temp.size(); j++) {
                vector<int> set = temp[j];
                set.insert(set.begin(), A[i]);
                res.push_back(set);
            }
        }
    }
    return res;
}

