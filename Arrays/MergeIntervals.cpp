vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> res;
    for(int i = 0; i < intervals.size(); i++) {
        if(intervals[i].end < newInterval.start) {
            res.push_back(intervals[i]);
        } else if(intervals[i].start > newInterval.end) {
            res.push_back(newInterval);
            newInterval = intervals[i];
        } else {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
        }
    }
    res.push_back(newInterval);
    return res;
}

