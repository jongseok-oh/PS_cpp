class Solution {
public:
    struct NumFreq{
        int num, freq;

        bool operator < (const NumFreq& other) const{
            return freq < other.freq;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int start = 0, n = nums.size();

        priority_queue<NumFreq> q;

        while(start < n){
            int idx = upper_bound(nums, nums[start]);

            q.push({nums[start], idx -  start});

            start = idx;
        }


        vector<int> ans;
        while(k--){
            ans.push_back(q.top().num);
            q.pop();
        }
        return ans;
    }

    int upper_bound(vector<int>& nums, int tar){
        int left = 0, right = nums.size();

        while(left +1 < right){
            int mid =(left + right) >>1;

            if(nums[mid] > tar) right = mid;
            else left = mid;
        }
        return right;
    }
};