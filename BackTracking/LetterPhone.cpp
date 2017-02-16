unordered_map<int, string> letters = { {0, "0"}, {1, "1"}, {2, "abc"}, {3,"def"}, {4,"ghi"},
            {5,"jkl"}, {6,"mno"}, {7,"pqrs"}, {8,"tuv"}, {9,"wxyz"}};
            
void letterComb(vector<string> &res, string &A, int idx, string &curr) {
    //cout << idx << " ";
    if(idx == A.size()) {
        res.push_back(curr);
        return;
    }
    
    string subs = letters[A[idx] - '0'];
    for(int j = 0; j < subs.size(); j++) {
        curr.push_back(subs[j]);
        letterComb(res, A, idx+1, curr);
        curr.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> res; string curr;
    letterComb(res, A, 0, curr);
    return res;
}

