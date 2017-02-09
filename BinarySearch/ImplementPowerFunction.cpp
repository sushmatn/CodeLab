long long powr(int x, int n, int d) {
    if(n == 0)
        return 1;
    if(n == 1)
        return x;
    long long res = powr(x,n/2,d);
    res = (res * res)%d;
    if(n % 2) {
        return (x*res) %d;
    } else {
        return res;
    }
}

int Solution::pow(int x, int n, int d) {
    long long res = powr(x%d, n, d);
    return (res + d) % d;
}

