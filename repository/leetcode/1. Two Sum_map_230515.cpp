class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        
        for(int i = 0, len = nums.size(); i<len; i++){
            int tTarget = target - nums[i];
            if(m.find(tTarget) != m.end()){
                return {i, m[tTarget]};
            }else m[nums[i]] = i;
        }
        return {};
    }
};