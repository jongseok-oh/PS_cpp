class Solution {

    void comb(int idx, int n, int k, vector<int> temp, vector<vector<int>>& ret){
        if(temp.size() == k){
            ret.push_back(temp); return;
        }

        for(int i = idx; i<=n; i++){
            vector<int> tt = temp;
            tt.push_back(i);
            comb(i + 1, n, k, tt, ret);
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        comb(1, n, k, vector<int>(), ret);
        return ret;
    }
};