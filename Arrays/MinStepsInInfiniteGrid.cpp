// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int steps = 0;
    
    for(int i = 1; i < X.size(); i++) {
        int x = abs(X[i] - X[i-1]);
        int y = abs(Y[i] - Y[i-1]);
        steps += max(x,y);
    }
    return steps;
}

