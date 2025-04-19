class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {

        int n = nums.size();

        int beforeNum = nums[n-1];
        long long ans = 0;
        
        for(int i = n-2; i>= 0; --i){
            if(beforeNum < nums[i]){
                int cal = nums[i]/beforeNum;

                if(nums[i]%beforeNum)++cal;
                beforeNum = nums[i]/cal;

                ans += cal - 1;
            }else beforeNum = nums[i];
        }

        return ans;
    }
};