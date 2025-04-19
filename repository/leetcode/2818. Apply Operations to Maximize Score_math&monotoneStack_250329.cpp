class Solution {
    using ll = long long;
    const int MOD = 1e9 + 7;
    int getPrimeScore(int num){
        int score = 0;
        for(int i = 2; i<=sqrt(num); ++i){
            if(num % i == 0){
                ++score;
                while(num % i == 0) num /= i;
            }
        }
        if(num >= 2) ++score;
        return score;
    }
    int pow(ll num, ll _pow){
        ll ret = 1;
        while(_pow){
            if(_pow&1) {
                ret = ret * num % MOD;
            }
            num = num * num % MOD;
            _pow >>= 1; 
        }
        return ret;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n);
        for(int i = 0; i<n; ++i){
            primeScores[i] = getPrimeScore(nums[i]);
        }

        stack<int> _stack;
        vector<int> left(n, -1), right(n, n-1);
        for(int i = 0; i<n; ++i){
            while(_stack.size()
            && primeScores[_stack.top()] < primeScores[i]){
                int idx = _stack.top(); _stack.pop();
                right[idx] = i - 1;
            }
            if(_stack.size()) left[i] = _stack.top();
            _stack.push(i);
        }

        auto cmp = [&nums](int idx1, int idx2){
            return nums[idx1] < nums[idx2];
        };
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        for(int i = 0; i<n; ++i) q.push(i);

        ll ret = 1;
        while(k){
            int idx = q.top(); q.pop();
            ll subArrayCnt = (ll)(idx - left[idx]) * (right[idx] - idx + 1);
            ll _min = min((ll)k, subArrayCnt);
            
            ret = ret * pow(nums[idx], _min) % MOD;
            k -= _min;
        }

        return ret;
    }
};