class Solution {
    using ll = long long;
public:
    ll putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> pairSum(n-1);
        for(int i = 0; i<n-1; ++i){
            pairSum[i] = weights[i] + weights[i+1];
        }
        sort(pairSum.begin(), pairSum.end());

        ll ret = 0;
        for(int i = 0; i<k-1; ++i){
            ret += pairSum[n-2-i] - pairSum[i];
        }
        return ret;
    }
};