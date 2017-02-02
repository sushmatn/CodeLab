int Solution::colorful(int A) {
    unordered_set<int> prods;
    string str = to_string(A);
    for(int i = 0; i < str.size(); i++) {
        int prod = 1;
        for(int j = i; j < str.size(); j++) {
            prod *= str[j] - '0';
            if(prods.find(prod) != prods.end()) {
                return false;
            }
            prods.emplace(prod);
        }
    }
    return true;
}

