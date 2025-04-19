class Solution {
    int win[100001], lose[100001];
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        for(auto& match: matches){
            ++win[match[0]];
            ++lose[match[1]];
        }

        vector<vector<int>> ret(2);

        for(int i = 1; i<= 100000; ++i){
            if(win[i] && !lose[i]) ret[0].push_back(i);
            else if(lose[i] == 1) ret[1].push_back(i);
        }
        
        return ret;
    }
};