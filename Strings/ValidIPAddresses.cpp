bool isValid(string str) {
    if(str[0] == '0' && str.size() > 1)
        return false;
    int val = stoi(str);
    return val >= 0 && val <= 255;
}

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> res;
    int N = A.size();
    for(int i = 1; i <= 3; i++) {
        string part1 = A.substr(0, i);
        if(!isValid(part1))
            continue;
        for(int j = 1; j <= 3 && i + j < N; j++) {
            string part2 = A.substr(i, j);
            if(!isValid(part2))
                continue;
            for(int k = 1; k <= 3 && i + j + k < N; k++) {
                string part3 = A.substr(i+j, k);
                if(!isValid(part3))
                    continue;
                for(int l = 1; l <= 3 && i + j + k + l <= N; l++) {
                    string part4 = A.substr(i+j+k, l);
                    if(!isValid(part4))
                        continue;
                    if(i+j+k+l == N)
                        res.push_back(part1 + "." + part2 + "." + part3 + "." + part4);
                }
            }
        }
    }
    return res;
}

