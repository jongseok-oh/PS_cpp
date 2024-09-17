class Solution {
    int solve(int l, int r, vector<int>& heights){
        if(l == r) return heights[l];
        
        int mid = (l + r)>>1;

        int ret = max(solve(l, mid, heights), solve(mid + 1, r, heights));
        int low = mid, high = mid + 1;
        int tH = min(heights[low], heights[high]);
        ret = max(ret, tH * 2);

        while(low > l || high < r){
            if(high < r && (low == l || heights[low - 1] <= heights[high + 1])){
                tH = min(tH, heights[++high]);
            }else {
                tH = min(tH, heights[--low]);
            }
            ret = max(ret, tH * (high - low + 1));
        }

        return ret;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 1) return heights[0];
        return solve(0, heights.size()-1, heights);
    }
};