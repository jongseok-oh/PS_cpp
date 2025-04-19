class Solution {
public:
    int kthGrammar(int n, int k) {
        --k;
        char bit = 0;
        int temp = pow(2, n-1);

        for(int i = n; i>1; --i){
            temp /= 2;
            if(k >= temp){
                bit^=1;
                k %= temp;
            }
        }
        return bit;
    }
};