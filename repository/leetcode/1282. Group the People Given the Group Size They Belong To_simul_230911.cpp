class Solution {
    vector<int> group[501];
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;

        for(int i = 0; i<groupSizes.size(); i++){
            int tg = groupSizes[i];
            group[tg].push_back(i);
            if(group[tg].size() == tg){
                ans.push_back(group[tg]);
                group[tg].clear();
            }
        }

        return ans;
    }
};