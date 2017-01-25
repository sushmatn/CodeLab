vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int> > res(A, vector<int>(A));
    int s = 1;
    int rS = 0, rE = A-1, cS = 0, cE = A-1;
    while(rS <= rE && cS <= cE) {
        // Go Right
        for(int i = cS; i <= cE; i++) {
            res[rS][i] = s++;
        }
        rS++;
        
        // Go down
        for(int i = rS; i <= rE; i++) {
            res[i][cE] = s++;
        }
        cE--;
        
        // Go left
        for(int i = cE; i >= cS; i--) {
            res[rE][i] = s++;
        }
        rE--;
        
        // Go up
        for(int i = rE; i >= rS; i--) {
            res[i][cS] = s++;
        }
        cS++;
    }
    return res;
}

