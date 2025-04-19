typedef pair<int,int> pii;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        auto cmp = [&nums1, &nums2](pii& a, pii& b){
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

        vector<vector<int>> ret;

        int n = nums1.size(), m = nums2.size();

        for(int i = 0; i<n; i++) pq.push({i,0});

        while(k-- && pq.size()){
            auto idxs = pq.top(); pq.pop();

            int nums1Idx = idxs.first;
            int nums2Idx = idxs.second;

            ret.push_back({nums1[nums1Idx], nums2[nums2Idx]});

            if(nums2Idx + 1 < m) pq.push({nums1Idx, nums2Idx + 1});
        }

        return ret;
    }
};