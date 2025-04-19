class Solution {
    int cnt[100001];
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int num: nums) cnt[num]++;
        for(int i = 1; i<=n; ++i)
            if(cnt[i] >= 2) return i;
        return -1;
    }
};