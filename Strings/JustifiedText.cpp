string getLine(vector<string> &A, int B, int i, int lastI, int spaceWidth, int extraSpace) {
    string res;
    for(int j = lastI; j < i; j++) {
        if(!res.empty()) {
            res.append(spaceWidth, ' ');
            if(extraSpace) {
                res += ' ';
                extraSpace--;
            }
        }
        res += A[j];
    }
    if(res.size() < B) {
        res.append(B - res.size(), ' ');
    }
    return res;
}

vector<string> Solution::fullJustify(vector<string> &A, int B) {
    int count = 0, lastI = 0;
    vector<string> res;
    for(int i = 0; i < A.size(); i++) {
        if(count + A[i].size() + i - lastI > B) {
            int spacesToAdd = i - lastI - 1;
            int spacesAvail = B - count;
            if(spacesToAdd == 0 || spacesToAdd == spacesAvail) {
                res.push_back(getLine(A, B, i, lastI, 1, 0));
            } else {
                int spaceWidth = spacesAvail/spacesToAdd;
                int extraSpace = spacesAvail % spacesToAdd;
                res.push_back(getLine(A, B, i, lastI, spaceWidth, extraSpace));
            }
            count = 0;
            lastI = i;
        }
        count += A[i].size();
    }
    if(count > 0) {
        res.push_back(getLine(A,B,A.size(),lastI,1,0));
    }
    return res;
}

