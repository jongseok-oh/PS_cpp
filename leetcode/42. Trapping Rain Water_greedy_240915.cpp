class Solution {
    vector<int> biggestHeightLeft(vector<int>& height){
        int n = height.size();
        vector<int> bhl(n);
        
        int prevBig = 0;
        for(int i = 0; i<n; ++i){
            bhl[i] = prevBig;
            prevBig = max(prevBig ,height[i]);
        }

        return bhl;
    }
    vector<int> biggestHeightRight(vector<int>& height){
        int n = height.size();
        vector<int> bhr(n);
        
        int prevBig = 0;
        for(int i = n -1; i>=0; --i){
            bhr[i] = prevBig;
            prevBig = max(prevBig ,height[i]);
        }

        return bhr;
    }
public:
    int trap(vector<int>& height) {
        vector<int> bhl = biggestHeightLeft(height);
        vector<int> bhr = biggestHeightRight(height);

        int rainWater = 0, n = height.size();
        for(int i = 0; i<n; ++i){
            int maxHeight = min(bhl[i], bhr[i]);
            if(maxHeight <= height[i]) continue;
            rainWater += maxHeight - height[i];
        }

        return rainWater;
    }
};