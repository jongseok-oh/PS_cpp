class Solution {
    using ll = long long;
public:
    ll maxMatrixSum(vector<vector<int>>& matrix) {
        ll sum = 0;
        int negativeCnt = 0, minAbs = 1e9;
        for(auto& row : matrix){
            for(int col : row){
                if(col < 0) ++negativeCnt;
                int absCol = abs(col);
                minAbs = min(minAbs, absCol);
                sum += absCol;
            }
        }

        return negativeCnt&1?sum -2*minAbs:sum;
    }
};