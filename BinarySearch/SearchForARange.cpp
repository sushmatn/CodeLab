int findLeftMostIdx(const vector<int> &A, int B, int s, int e) {
    if(s > e)
        return -1;
    int ret = -1;
    while(s <= e) {
        int mid = s + (e-s)/2;
        if(A[mid] == B) {
            ret = mid;
            e = mid -1;
        } else if(A[mid] < B) {
            s = mid + 1;
        } else {
            e = mid -1;
        }
    }
    return ret;
}

int findRightMostIdx(const vector<int> &A, int B, int s, int e) {
    if(s > e)
        return -1;
    int ret = -1;
    while(s <= e) {
        int mid = s + (e-s)/2;
        if(A[mid] == B) {
            ret = mid;
            s = mid +1;
        } else if(A[mid] < B) {
            s = mid + 1;
        } else {
            e = mid -1;
        }
    }
    return ret;
}
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    vector<int> res = { findLeftMostIdx(A, B, 0, A.size() -1), findRightMostIdx(A, B, 0, A.size() -1)};
    return res;
}

