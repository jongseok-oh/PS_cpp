class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ret(pref.size());

        ret[0] = pref[0];

        for(int i = 1; i<pref.size(); ++i)
            ret[i] = pref[i-1] ^ pref[i];
        
        return ret;
    }
};