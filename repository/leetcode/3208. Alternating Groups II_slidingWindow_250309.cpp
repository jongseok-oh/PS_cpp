class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int prevColor = colors[0], prevGroup = 1;
        for(int i = 1; i<k-1; ++i){
            if(prevColor != colors[i]){
                prevColor = colors[i];
                ++prevGroup;
            }else{
                prevGroup = 1;
            }
        }

        int ret = 0;
        for(int i = k-1; i<n + k -1; ++i){
            if(colors[i%n] != prevColor) {
                prevColor = colors[i%n];
                ++prevGroup;
            }else{
                prevGroup = 1;
            }
            if(prevGroup == k){
                ++ret;
                --prevGroup;
            }
        }

        return ret;
    }
};