int Solution::nchoc(int A, vector<int> &B) {
    const long long TO_MOD = pow(10,9) + 7;
    priority_queue<int> q;
    for(int i = 0; i < B.size(); i++) {
        q.push(B[i]);
    }
    
    int time = 0;
    long long count = 0;
    while(time < A && !q.empty()) {
        long long val = q.top();
        q.pop();
        if(val/2 > 0)
            q.push(val/2);
        val %= TO_MOD;
        count += val;
        count %= TO_MOD;
        time++;
    }
    return count;
}

