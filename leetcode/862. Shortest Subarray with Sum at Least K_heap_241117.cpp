class Solution {
    using ll = long long;
    using plli = pair<ll,int>;
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<plli, vector<plli>, greater<>> q;
        
        int ret = 1e9;
        ll sum = 0;
        for(int i = 0, n = nums.size(); i<n; ++i){
            sum += nums[i];
            if(sum >= k) ret = min(ret, i + 1);
            while(q.size()){
                auto [prevSum, idx] = q.top();
                if(sum - prevSum >= k){
                    ret = min(ret, i - idx);
                    q.pop();
                }else break;
            }
            q.emplace(sum, i);
        }

        return ret == 1e9?-1:ret;
    }
};