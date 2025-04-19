class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int totXor = 0;
        for(int bit : derived){
            totXor ^= bit;
        }
        return !totXor;
    }
};