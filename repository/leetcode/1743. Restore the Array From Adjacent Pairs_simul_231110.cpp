class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ap) {
        int n = ap.size() + 1;
        unordered_map<int, vector<int>> next;

        for(auto& p: ap){
            next[p[0]].push_back(p[1]);
            next[p[1]].push_back(p[0]);
        }

        int start = -1;
        for(auto& nn: next){
            if(nn.second.size() == 1){
                start = nn.first; break;
            }
        }

        vector<int> ret;
        unordered_set<int> visit;
        visit.insert(start);
        ret.push_back(start);

        int temp = start;
        while(ret.size() != n){
            for(int tt :next[temp]){
                if(visit.find(tt) == visit.end()){
                    temp = tt; break;
                }
            }
            visit.insert(temp);
            ret.push_back(temp);
        }

        return ret;
    }
};