class Solution {
    long long dp[1024];
public:
    long long wonderfulSubstrings(string word) {
        dp[0] = 1;
        
        int preXor = 0;
        long long ret = 0;
        for(char c: word){
            preXor ^= 1<<(c-'a');
            ret += dp[preXor];
            for(int i = 0; i<10; ++i){
                int cnt = dp[preXor ^ (1<<i)];
                if(cnt) ret += cnt;
            }
            dp[preXor]++;
        }
        
        return ret;
    }
};