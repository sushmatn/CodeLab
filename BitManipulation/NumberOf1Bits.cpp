int Solution::numSetBits(unsigned int A) {
    int count = 0, temp = A;
    while(temp) {
        count++;
        temp = temp & (temp-1);
    }
    return count;
}

