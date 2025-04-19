class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        
        int rainWater = 0;
        int l = 0, r = height.size()-1;
        int maxL = height[l], maxR = height[r];
        while(l + 1 < r){
            if(height[l] <= height[r]){
                maxL = max(maxL, height[++l]);
                int calcWater = min(maxL, maxR) - height[l];
                if(calcWater > 0) {
                    rainWater += calcWater;
                }
            }else{
                maxR = max(maxR, height[--r]);
                int calcWater = min(maxL, maxR) - height[r];
                if(calcWater > 0) {
                    rainWater += calcWater;
                }
            }
        }

        return rainWater;
    }
};