unsigned int Solution::reverse(unsigned int A) {
    unsigned int i = 0, j = 31;
    while(i < j) {
        if( ((A >> i) & 0x1) != ((A >> j) & 0x1)) {
            int val = (1 << i) | (1 << j);
            A ^= val;
        }
        i++; j--;
    }
    return A;
}

