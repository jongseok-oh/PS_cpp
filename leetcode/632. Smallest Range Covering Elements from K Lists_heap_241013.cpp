class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int,int,int>>, greater<>> q;
        
        int _max = -1e9;
        for(int i = 0; i<k; ++i){
            int val = nums[i][0];
            _max = max(_max, val);
            q.emplace(val, i, 0);
        }

        int start = -1e9, end = 1e9;
        while(q.size() == k){
            auto [minVal, row, col] = q.top(); q.pop();

            if(_max - minVal < end - start){
                start = minVal;
                end = _max;
            }
            
            if(col + 1 < nums[row].size()){
                int nextVal = nums[row][col + 1];
                _max = max(_max, nextVal);
                q.emplace(nextVal, row, col + 1);
            }
        }

        return {start, end};
    }
};