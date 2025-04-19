class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;
        for(int num: nums1) set1.insert(num);
        for(int num: nums2){
            if(set1.find(num) != set1.end())
                set2.insert(num);
        }
        vector<int> ret;
        ret.insert(ret.end(), set2.begin(), set2.end());
        return ret;
    }
};