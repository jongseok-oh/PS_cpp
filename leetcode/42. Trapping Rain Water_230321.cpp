class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> cache = vector<int>(n);
        
        for(int i = n -2; i>=0; i--)
            cache[i] = max(cache[i+1], height[i+1]);
        
        int leftMax = height[0];

        int ans = 0;
        for(int i = 1; i<n-1; i++){
            int tmax = min(leftMax, cache[i]);
            if(tmax > height[i]) ans += tmax - height[i];
            leftMax = max(leftMax, height[i]);
        }
        return ans;
    }
};