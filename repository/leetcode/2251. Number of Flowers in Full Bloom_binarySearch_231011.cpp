class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, end;
        for(auto& f: flowers)
            start.push_back(f[0]), end.push_back(f[1]);
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int n = people.size();
        vector<int> ret(n);

        for(int i = 0; i<n; ++i){
            int tar = people[i];
            int s = upper_bound(start.begin(), start.end(), tar) - start.begin();
            int e = lower_bound(end.begin(), end.end(), tar) - end.begin();
            ret[i] = s-e;
        }

        return ret;
    }
};