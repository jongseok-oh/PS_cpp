class Solution {
    using pii = pair<int,int>;
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pii, vector<pii>, greater<>> q;
        for(int i = 0, n = nums.size(); i<n; ++i){
            q.emplace(nums[i], i);
        }

        while(k--){
            auto [value, idx] = q.top(); q.pop();
            q.emplace(value * multiplier, idx);
        }

        while(q.size()){
            auto [value, idx] = q.top(); q.pop();
            nums[idx] = value;
        }
        return nums;
    }
};