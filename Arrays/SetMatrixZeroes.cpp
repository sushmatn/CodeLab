void Solution::setZeroes(vector<vector<int> > &A) {
    bool rows[A.size()];
    bool cols[A[0].size()];
    
    fill_n(rows, A.size(), 1);
    fill_n(cols, A[0].size(), 1);
    
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            if(A[i][j] == 0) {
                rows[i] = 0;
                cols[j] = 0;
            }
        }
    }

    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < A[0].size(); j++) {
            if(rows[i] == 0 || cols[j] == 0) {
                A[i][j] = 0;
            }
        }
    }
}

