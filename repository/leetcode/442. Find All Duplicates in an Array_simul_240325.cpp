class Solution {
    int cnt[100001];
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(int num: nums) ++cnt[num];
        
        vector<int> ret;
        for(int i = 1; i<=n; ++i)
            if(cnt[i] >= 2) ret.push_back(i);

        return ret;
    }
};