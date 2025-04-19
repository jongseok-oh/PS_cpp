class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> cache;
        for(int num : nums1) cache[num]++;

        for(int num : nums2){
            if(cache.count(num)){
                ret.push_back(num);
                if(--cache[num] == 0) cache.erase(num);
            }
        }
        return ret;
    }
};