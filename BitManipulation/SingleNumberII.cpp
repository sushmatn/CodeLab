int Solution::singleNumber(const vector<int> &A) {
    int once = 0, twice = 0;
    for(int i = 0; i < A.size(); i++) {
        twice |= once & A[i];
        once ^= A[i];
        int thrice = ~(twice & once);
        once &= thrice;
        twice &= thrice;
    }
    return once;
}

