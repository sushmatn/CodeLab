vector<vector<int> > Solution::prettyPrint(int A) {
    int count = (2*A) -1;

    vector<vector<int> >res(count, vector<int>(count));
    int row = 0, col = 0, maxRow = count-1, maxCol = count-1;
    while(row <= maxRow && col <= maxCol) {
        for(int i = col; i <= maxCol; i++) {
            res[row][i] = A;
        }
        row++;
        for(int i = row; i <= maxRow; i++) {
            res[i][maxCol] = A;
        }
        maxCol--;
        for(int i = maxCol; i >= col; i--) {
            res[maxRow][i] = A;
        }
        maxRow--;
        for(int i = maxRow; i >= row; i--) {
            res[i][col] = A;
        }
        col++;
        A--;
    }
    return res;
}

