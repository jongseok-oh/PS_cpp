class Solution {

    int getTime(int t, vector<vector<int>>& child, vector<int>& informTime){
        
        int ret = informTime[t];

        int _max = 0;
        for(int ch: child[t]) _max = max(_max,getTime(ch, child, informTime));

        return ret + _max;
    }

public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> child(n);

        for(int i = 0; i<n; i++)
            if(manager[i] != -1) child[manager[i]].push_back(i);
        
        return getTime(headID, child, informTime);
    }
};