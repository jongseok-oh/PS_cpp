class Solution {
    int solve(int n, int k, vector<int>& length){
        if(n == 1) return 0;
        int half = length[n -1]/2;
        if(k == half) return 1;
        if(k < half) return solve(n-1, k, length);
        return solve(n-1, half - (k - half), length)^1;
    }
public:
    char findKthBit(int n, int k) {
        vector<int> length(20);
        length[0] = 1;
        for(int i = 1; i<20; ++i) {
            length[i] = length[i-1] * 2 + 1;
        }
        return solve(n, k-1, length) + '0';
    }
};