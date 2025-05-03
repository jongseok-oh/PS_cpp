class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ret = 1e9, n = tops.size();
        for(int num = 1; num<=6; ++num){
            bool canChange = true;
            int same = 0, change = 0;
            for(int i = 0; i<n; ++i){
                if(tops[i] == num){
                    if(bottoms[i] == num) ++same;
                }else{
                    if(bottoms[i] != num){
                        canChange = false;
                    }else ++change;
                }
            }

            if(canChange){
                ret = min({ret, change, n - same - change});
            }
        }

        return ret == 1e9?-1:ret;
    }
};