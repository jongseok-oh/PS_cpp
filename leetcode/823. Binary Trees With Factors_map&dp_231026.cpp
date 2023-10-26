class Solution {
    const int MOD = 1e9 + 7;
    typedef long long ll;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, int> dp;

        int ret = 0;
        sort(arr.begin(), arr.end());

        for(int& num : arr){
            dp[num] = 1;
            for(int& div: arr){
                if(div > sqrt(num)) break;
                if(num % div == 0 && dp.find(num/div) != dp.end()){
                    ll temp = (ll)dp[div] * dp[num/div] % MOD;
                    
                    if(num / div == div){
                        dp[num] = (temp + dp[num]) % MOD;
                    }else dp[num] = (temp*2 + dp[num]) % MOD;
                }
            }
            ret = (ret + dp[num]) % MOD;
        }

        return ret;
    }
};