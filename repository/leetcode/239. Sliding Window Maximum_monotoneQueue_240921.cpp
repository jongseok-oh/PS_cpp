class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // monotone queue
        deque<int> dq;
        for(int i = 0; i<k-1; ++i){
            while(dq.size() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        vector<int> ret;
        for(int i = k-1, n = nums.size(); i<n; ++i){
            while(dq.size() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            ret.push_back(nums[dq.front()]);
            if(dq.front() == i - (k-1)) {
                dq.pop_front();
            }
        }

        return ret;
    }
};