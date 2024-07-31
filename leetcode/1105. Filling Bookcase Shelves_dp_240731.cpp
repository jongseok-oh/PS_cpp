class Solution {
    int dp[1000][1001]; // [idx][width]
    int solve(int idx, int width, int prevMaxHeight, int shelfWidth, vector<vector<int>>& books){
        if(idx == books.size()) return 0;
        int& ret = dp[idx][width];
        if(ret != -1) return ret;
        
        ret = 1e9;
        int thick = books[idx][0], height = books[idx][1];
        if(width + thick <= shelfWidth){
            int diff = height - prevMaxHeight;
            ret = solve(idx + 1, width + thick, max(prevMaxHeight, height), shelfWidth, books)
            + (diff>0?diff:0);
        }
        return ret = min(ret, solve(idx + 1, thick, height, shelfWidth, books) + height);
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp, -1, sizeof dp);
        return solve(0,0,0,shelfWidth,books);
    }
};