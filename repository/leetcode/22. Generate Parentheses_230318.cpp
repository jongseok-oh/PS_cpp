class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;

        for(int i = 0; i<(1<<2*n); i++){

            int j = n*2-1, cnt = 0;
            for(; j>=0; j--){
                cnt += (i & (1<<j))?1:-1;
                if(cnt <0) break;
            }
            
            if(j <0 && !cnt) {
                string t;
                for(int k = n*2-1; k>=0; k--) t.push_back((i & (1<<k))?'(':')');
                ret.push_back(t);
            }
        }
        return ret;
    }
};