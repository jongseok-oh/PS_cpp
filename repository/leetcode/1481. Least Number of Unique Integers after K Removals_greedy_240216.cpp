class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;

        for(int num: arr) ++m[num];

        vector<pair<int,int>> vec(m.begin(), m.end());
        sort(vec.begin(), vec.end(), [&](auto& t1, auto& t2){
            return t1.second < t2.second;
        });

        int ret = vec.size();
        for(auto& [_, cnt] : vec){
            if(cnt <= k) {--ret; k-=cnt;}
            else break;
        }

        return ret;
    }
};