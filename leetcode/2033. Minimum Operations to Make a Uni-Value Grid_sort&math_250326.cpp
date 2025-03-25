class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int mod = grid[0][0] % x;
        
        int right = 0;
        vector<int> elements;
        for(auto& row : grid){
            for(int element : row){
                if(element % x != mod) return -1;
                elements.push_back(element);
                right += element;
            }
        }

        int n = elements.size();
        sort(elements.begin(), elements.end());

        right -= n * mod;
        int left = 0, ret = 1e9;
        for(int i = 0; i<n; ++i){
            int element = elements[i] - mod;
            right -= element;
            // (i * element - left + right - (n - i - 1) * element) / x
            // (element * (1-n + 2*i) -left + right) /x
            ret = min(ret, (element * (1-n + 2*i) -left + right) /x);
            left += element;
        }
        
        return ret;
    }
};