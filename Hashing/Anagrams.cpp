vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string, vector<int> > words;
    for(int i =0; i < A.size(); i++) {
        string word = A[i];
        sort(word.begin(), word.end());
        words[word].push_back(i+1);
    }
    
    vector<vector<int> > res;
    for(auto it = words.begin(); it != words.end(); it++) {
        res.push_back(it->second);
    }
    
    return res;
}

