class Solution {
public:
    int minOperations(string s) {
        int ret1 = 0 , ret2 = 0;
        
        int c1 = 0, c2 = 1; 
        for(char& c: s){
            if(c1 != c -'0') ret1++;
            if(c2 != c - '0') ret2++;
            c1 ^= 1, c2 ^= 1;
        }

        return min(ret1, ret2);
    }
};