class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> rowHash31(n);
        vector<int> rowHash37(n);
        vector<int> colHash31(n);
        vector<int> colHash37(n);

        for(int i = 0; i<n; i++){
            int hash31 = 0;
            int hash37 = 0;
            for(int j = 0; j<n; j++){
                hash31 = (1LL * hash31 * 31 + grid[i][j]) % 0x7fffffff;
                hash37 = (1LL * hash37 * 37 + grid[i][j]) % 0x7fffffff;
            }
            
            rowHash31[i] = hash31;
            rowHash37[i] = hash37;
        }

        for(int j = 0; j<n; j++){
            int hash31 = 0;
            int hash37 = 0;
            for(int i = 0; i<n; i++){
                hash31 = (1LL * hash31 * 31 + grid[i][j]) % 0x7fffffff;
                hash37 = (1LL * hash37 * 37 + grid[i][j]) % 0x7fffffff;
            }
            colHash31[j] = hash31;
            colHash37[j] = hash37;
        }

        int ans = 0;
        for(int i = 0; i<n; i++) for(int j = 0; j<n; j++)
            if(rowHash31[i] == colHash31[j] && rowHash37[i] == colHash37[j]) ans++;
        
        return ans;
    }
};