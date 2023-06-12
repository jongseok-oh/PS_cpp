class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        int n = nums.size();

        if(!n) return ans;

        int start = nums[0];
        int temp = nums[0];

        for(int i = 0; i<n; i++){
            temp = nums[i];
            if(i + 1 == n || nums[i+1] != temp + 1){
                string t = to_string(start);
                if(nums[i] != start) t += "->" + to_string(nums[i]);

                ans.push_back(t);
                if(i != n-1) start = nums[i + 1];
            }
        }

        return ans;
    }
};