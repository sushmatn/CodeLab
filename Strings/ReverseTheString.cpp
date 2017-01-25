void reverse(string &A, int s, int e) {
    while(s < e) {
        swap(A[s++], A[e--]);
    }    
}

void trimSpaces(string &A) {
    auto it = A.begin();
    while(*it == ' ' && it != A.end()) {
        auto next = it+1;
        A.erase(it);
    }
}
// the sky is blue
void Solution::reverseWords(string &A) {
    if(A.size() <= 1)
        return;
        
    int s = 0;
    trimSpaces(A);
    reverse(A, 0, A.size() -1);
    trimSpaces(A);
    
    // Remove extra spaces
    vector<int> toRemove;
    for(int i = 0; i < A.size()-1; i++) {
        if(A[i] == ' ' && A[i+1] == ' ')
            toRemove.push_back(i);
    }
    
    for(int i = toRemove.size() -1; i >= 0; i--) {
        A.erase(A.begin() + toRemove[i]);
    }
    
    for(int i = s; i < A.size(); i++) {
        if(A[i] == ' ' || i == A.size() -1) {
            reverse(A, s, i == A.size() -1 ? i: i-1);
            s = i+1;
            while(s < i && A[s] == ' ') {
                A.erase(A.begin() + s);
            }
        }
    }
}

