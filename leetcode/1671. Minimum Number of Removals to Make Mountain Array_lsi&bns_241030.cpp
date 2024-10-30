class Solution {
    int LDS(int idx, vector<int>& nums){
        int pointer = 0;
        vector<int> temp;
        
        for(int i = 0; i<=idx; ++i){
            int num = nums[i];
            if(num > nums[idx]) continue;
            auto it = lower_bound(temp.begin(), temp.end(), num);
            if(it == temp.end()) temp.push_back(num);
            else *it = num;
        }

        return temp.size();
    }
    int LIS(int idx, vector<int>& nums){
        int pointer = 0, n = nums.size();
        vector<int> temp;

        for(int i = n-1; i>=idx; --i){
            int num = nums[i];
            if(num > nums[idx]) continue;
            auto it = lower_bound(temp.begin(), temp.end(), num);
            if(it == temp.end()) temp.push_back(num);
            else *it = num;
        }

        return temp.size();
    }
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        int ret = 1e9;
        for(int i = 1; i<n-1; ++i){
            int lds = LDS(i, nums); if(lds <= 1) continue;
            int lis = LIS(i, nums); if(lis <= 1) continue;
            ret = min(ret, n - (lds + lis - 1));
        }

        return ret;
    }
};