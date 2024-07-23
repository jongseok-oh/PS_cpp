class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> cache;
        for(int num : nums) ++cache[num];
        vector<pair<int,int>> vec(cache.begin(), cache.end());
        
        sort(vec.begin(), vec.end(), [&](auto& a, auto& b){
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        });

        vector<int> ret;
        for(auto [num, cnt] : vec){
            while(cnt--) ret.push_back(num);
        }
        return ret;
    }
};