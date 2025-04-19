class Solution {
    using ll = long long;
    using pii = pair<int, int>;
public:
    ll findScore(vector<int>& nums) {
        priority_queue<pii, vector<pii>, greater<>> q;

        int n = nums.size();
        for(int i = 0; i<n; ++i){
            q.emplace(nums[i], i);
        }

        ll score = 0;
        bitset<100002> mark;
        while(q.size()){
            auto [num, idx] = q.top(); q.pop();
            if(mark[idx + 1]) continue;

            score += num;
            for(int i = 0; i<3; ++i){
                mark[idx+i] = 1;
            }
        }

        return score;
    }
};