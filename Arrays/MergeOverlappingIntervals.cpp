/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

int compare(Interval i1, Interval i2) {
    return i1.start < i2.start;
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> res;
    if(A.empty())
        return A;
    sort(A.begin(), A.end(), compare);
    Interval curr = A[0];
    for(int i = 1; i < A.size(); i++) {
        if(curr.end < A[i].start) {
            res.push_back(curr);
            curr = A[i];
        } else {
            curr.start = min(curr.start, A[i].start);
            curr.end = max(curr.end, A[i].end);
        }
    }
    res.push_back(curr);
    return res;
}

