class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ret = 0, temp  = 0;
        
        for(int i = 0; i<gain.size(); i++){
            temp += gain[i];
            ret = max(ret, temp);
        }

        return ret;
    }
};