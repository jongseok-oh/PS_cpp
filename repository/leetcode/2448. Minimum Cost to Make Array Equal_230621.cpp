class Solution {
    long long calc(vector<int>& nums, vector<int>& cost, int tar){
        
        long long ret = 0;
        for(int i = 0; i<nums.size(); i++){
            ret += 1LL * abs(nums[i] - tar) * cost[i];
        }

        return ret;
    }

public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int low = 1e9, high = -1;

        for(int num : nums){
            low = min(low, num);
            high = max(high, num);
        }

        low--; high++;
        long long ans = 0;
        while(low + 1 < high){
            int mid = (low + high)>>1;

            long long cost1 = calc(nums, cost, mid);
            long long cost2 = calc(nums, cost, mid + 1);

            if(cost1 <= cost2){
                high = mid;
                ans = cost1;
            }else{
                low = mid;
                ans = cost2;
            }
        }

        return ans;
    }
};