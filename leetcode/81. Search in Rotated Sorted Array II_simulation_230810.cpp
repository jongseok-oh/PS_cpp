class Solution {
public:
    bool search(vector<int>& nums, int target) {
       for(auto& num: nums) if(target == num) return true;
       return false;
    }
};