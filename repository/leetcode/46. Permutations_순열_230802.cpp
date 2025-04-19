class Solution {
    vector<int> temp;
    bool visit[6];

    void solve(int cnt, vector<int>& nums, vector<vector<int>>& ret){
        if(cnt == nums.size()) {
            ret.push_back(temp);
            return;
        }

        for(int i = 0; i<nums.size(); i++){
            if(visit[i]) continue;
            visit[i] = true;
            temp[cnt] = nums[i];
            solve(cnt + 1, nums, ret);
            visit[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        temp.resize(nums.size());
        vector<vector<int>> ret;
        solve(0, nums, ret);
        return ret;
    }
};