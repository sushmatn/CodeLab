bool isValid(vector<int> &cols, int row) {
    int lastCol = cols[row];
    for(int i = 0; i < row; i++) {
        if(cols[i] == lastCol || (abs(row-i) == abs(cols[i] - lastCol)))
            return false;
    }
    return true;
}

void solve(vector<vector<string> > &res, int A, vector<int> &cols, int row) {
    if(row == A) {
        vector<string> soln;
        for(int i = 0; i < A; i++) {
            string temp;
            for(int j=0; j <A; j++) {
                if(cols[i] == j)
                    temp+= "Q";
                else
                    temp+=".";
            }
            soln.push_back(temp);
        }
        res.push_back(soln);
        return;
    }
    for(int i = 0; i < A; i++) {
        cols[row] = i;
        if(isValid(cols, row)) {
            solve(res, A, cols, row+1);
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string> > res;
    vector<int> cols(A,0);
    solve(res, A, cols, 0);
    return res;
}

