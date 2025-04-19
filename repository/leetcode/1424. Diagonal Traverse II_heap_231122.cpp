class Solution {
    struct Loc{
        int y, x, v;
        
        bool operator < (const Loc& a) const{
            int sum = y + x, aSum = a.y + a.x;
            return (sum == aSum && y < a.y) || sum > aSum;
        }
    };
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        priority_queue<Loc> q;

        int n = nums.size(), len = 0;
        for(int i = 0; i<n; ++i){
            int m = nums[i].size();
            len += m;
            for(int j = 0; j<m; ++j) q.push({i,j,nums[i][j]});
        }
        
        int idx = 0;
        vector<int> ret(len);

        while(q.size()){
            ret[idx++] = q.top().v, q.pop();
        }

        return ret;
    }
};