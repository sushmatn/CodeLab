string Solution::fractionToDecimal(int numerator, int denominator) {
    string res;
    long num = (long)numerator, den = (long)denominator;
    
    if(numerator == 0)
        return "0";
    
    if((num < 0 || den < 0 ) && !(num < 0 && den < 0)) {
        res += "-";
    }
    num = abs(num); den = abs(den);
    res += to_string(num/den);
    
    long rem = num % den;
    if( rem == 0)
        return res;
    res += ".";
    
    unordered_map<int, int> seen;
    while(rem) {
        if(seen.find(rem) != seen.end()) {
            res.insert(seen[rem], "(");
            res += ")";
            break;
        }
        seen[rem] = res.size();
        res += to_string(rem * 10 / den);
        rem = (rem * 10) % den;
    }
    return res;
}

