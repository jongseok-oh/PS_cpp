class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> set;
        int _min = 1e9;
        for(int num : nums){
            _min = min(_min, num);
            set.insert(num);
        }

        if(k > _min) return -1;
        
        return _min == k?set.size()-1:set.size();
    }
};