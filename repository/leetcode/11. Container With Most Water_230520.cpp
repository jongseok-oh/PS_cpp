class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0, right = height.size()-1;
        int ret = -1;

        while(left < right){
            int h = min(height[left], height[right]);
            int w = right - left;

            ret = max(ret, w * h);

            if(height[left] < height[right]) left++;
            else right--;
        }
        return ret;
    }
};