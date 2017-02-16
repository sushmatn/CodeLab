void generate(vector<string> &res, int left, int right, string curr) {
    if(right < left)
        return;
        
    if(left == 0 && right == 0) {
        res.push_back(curr);
        return;
    }
    
    if(left > 0) {
        generate(res, left-1, right, curr + '(');
    }    
    if(right > 0) {
        generate(res, left, right-1, curr + ')');
    }
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> res;
    generate(res, A, A, "");
    return res;
}

