class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        for(int start = 0, n = s.size(); start<n; ++start){
            bool invalid = false;
            for(int i = 0; i<n; ++i){
                if(s[(start + i)%n] != goal[i]){
                    invalid = true; break;
                }
            }
            if(!invalid) return true;
        }
        return false;
    }
};