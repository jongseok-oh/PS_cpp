class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ret;

        int cur = 1;
        for(int tar: target){
            while(cur++ < tar){
                ret.push_back("Push");
                ret.push_back("Pop");
            }
            ret.push_back("Push");
        }
        
        return ret;
    }
};