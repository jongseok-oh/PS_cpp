class Solution {
    using pii = pair<int, int>;
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<pii> subSpecial;

        for(int i = 0; i<n;){
            int j = i+1;
            while(j < n && ((nums[j-1]&1)^(nums[j]&1))){
                ++j;
            }
            subSpecial.emplace_back(j-1, i);
            i = j;
        }

        int m = queries.size();
        vector<bool> ret(m);
        for(int i = 0; i<m; ++i){
            int from = queries[i][0], to = queries[i][1];
            auto [sTo, sFrom] = *lower_bound(subSpecial.begin(), subSpecial.end(), make_pair(to, -1));
            ret[i] = sFrom <= from && sTo >= to;
        } 
        return ret;
    }
};