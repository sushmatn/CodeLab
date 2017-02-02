int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    if(A.size() <= 1)
        return A.size();
        
    int maxPoints = 1;
    for(int i = 0; i < A.size(); i++) {
        unordered_map<double, int> slopes; int samePt = 0, points = 1;
        for(int j = i+1; j < A.size(); j++) {
            double slope = numeric_limits<double>::infinity();
            if(A[i] == A[j] && B[i] == B[j]) {
                samePt++;
                continue;
            } else if(A[i] != A[j]) {
                slope = (1.0*(B[j] - B[i]))/(A[j] - A[i]);
            }
            if(slopes.find(slope) == slopes.end()) {
                slopes[slope] = 2;
            } else {
                slopes[slope]++;
            }
            points = max(points, slopes[slope]);
        }
        maxPoints = max(maxPoints, points + samePt);
    }
    return maxPoints;
}

