class Solution {
    using pii = pair<int, int>;
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pii> vec;
        for(int i = 0; i<n; ++i){
            vec.emplace_back(nums[i], i);
        }
        sort(vec.begin(), vec.end());

        vector<int> ret(n);
        for(int i = 0; i<n;){
            int start = i;
            vector<int> familyIdx;
            familyIdx.push_back(vec[i].second);
            ++i;
            while(i < n && vec[i].first - nums[familyIdx.back()] <= limit){
                familyIdx.push_back(vec[i].second);
                ++i;
            }

            sort(familyIdx.begin(), familyIdx.end());
            for(int j = 0, m = familyIdx.size(); j<m; ++j){
                ret[familyIdx[j]] = vec[start + j].first;
            }
        }

        return ret;
    }
};