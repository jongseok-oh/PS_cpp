class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> set;
        unordered_map<int, int> map;

        for(int num : arr) set.insert(num);
        int order = 1;
        for(int num : set) map[num] = order++;

        int n = arr.size();
        vector<int> ret(n);

        for(int i = 0; i<n; ++i){
            ret[i] = map[arr[i]];
        }

        return ret;
    }
};