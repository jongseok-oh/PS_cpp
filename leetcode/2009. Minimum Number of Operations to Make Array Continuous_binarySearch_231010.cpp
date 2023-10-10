class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        
        vector<int> s(nums.begin(), unique(nums.begin(), nums.end()));

        int ret = 1e9;
        for(auto it = s.begin(); it != s.end(); ++it){
            int tar = *it + n - 1;
            auto end = upper_bound(it, s.end(), tar);

            int dist = distance(it, end);

            ret = min(ret, n - dist);
        }

        return ret;
    }
};