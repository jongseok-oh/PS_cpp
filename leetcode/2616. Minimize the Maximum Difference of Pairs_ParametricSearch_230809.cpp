class Solution {
    bool chk(vector<int>& nums, int mid, int p){
        int cnt = 0;

        for(int i = 0; i<nums.size()-1 && cnt < p;){
            if(nums[i + 1] - nums[i] <= mid) ++cnt, i += 2;
            else ++i;
        }

        return cnt == p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int low = -1, high = nums.back() - nums.front();

        while(low + 1 < high){
            int mid = (low + high)>>1;
            if(chk(nums, mid, p)) high = mid;
            else low = mid;
        }

        return high;
    }
};