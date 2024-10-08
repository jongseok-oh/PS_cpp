class Solution {
public:
    int minSwaps(string s) {
        int left = 0;
        for(char c : s){
            if(c == '[') ++left;
            else {
                if(left != 0) --left;
            }
        }
        return left / 2 + (left&1);
    }
};