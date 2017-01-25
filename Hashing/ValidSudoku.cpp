int Solution::isValidSudoku(const vector<string> &A) {
    const int LEN = 9;

    // Check all rows
    for(int i = 0; i < A.size(); i++) {
        bool found[LEN];
        fill_n(found, LEN, 0);
        for(int j = 0; j < LEN; j++) {
            if(A[i][j] == '.')
                continue;
            int val = A[i][j] - '0';
            if(found[val-1]) 
                return false;
            found[val-1] = true;
        }
    }
    
    // Check all columns
    for(int i = 0; i < LEN; i++) {
        bool found[LEN];
        fill_n(found, LEN, 0);
        for(int j = 0; j < A.size(); j++) {
            if(A[j][i] == '.')
                continue;
            int val = A[j][i] - '0';
            if(found[val-1]) 
                return false;
            found[val-1] = true;
        }
    }
    
    // Check all 3x3 squares
    // 0,3,6
    for(int i = 0; i < LEN; i += 3) {       
        for(int j = 0; j < LEN; j += 3) {   
            bool found[LEN];    
            fill_n(found, LEN, 0);
            for(int k = i; k < i+3; k++) {      
                for(int l = j; l < j+3; l++) {  
                    if(A[k][l] == '.')          
                        continue;               
                    int val = A[k][l] - '0';    
                    if(found[val-1]) 
                        return false;
                    found[val-1] = true;
                }
            }
        }
    }
    return true;
}

