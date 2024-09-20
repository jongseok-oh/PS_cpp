class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        multiset<int> window;
        for(int i = 0; i<k-1; ++i) window.insert(nums[i]);

        vector<int> ret;
        for(int i = k-1; i<n; ++i){
            window.insert(nums[i]);
            ret.push_back(*window.rbegin());
            window.erase(window.find(nums[i-k+1]));
        }

        return ret;
    }
};