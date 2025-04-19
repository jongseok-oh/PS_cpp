class Solution {
    typedef long long ll;
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        bitset<33> bit(n);
        return bit.count() == 1;
    }
};