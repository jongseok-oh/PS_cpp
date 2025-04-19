class Solution {

    bool chars[26];
    
public:
    int largestVariance(string s) {
        int n = s.size();

        for(char& c: s) chars[c-'a'] = true;

        int ans = 0;
        for(int run = 0; run<2; run++){
            for(int i = 0; i<26; i++){
                for(int j = 0; j<26; j++){
                    if(i == j || !chars[i] || !chars[j]) continue;

                    int cnt1 = 0, cnt2 = 0;

                    for(char& c: s){
                        int num = c - 'a';

                        if(num == i) cnt1++;
                        else if(num == j) cnt2++;

                        if(cnt1 < cnt2){
                            cnt1 = 0; cnt2 = 0;
                        } else if(cnt1 > 0 && cnt2 > 0)
                            ans = max(ans, cnt1 - cnt2);
                    }
                }
            }
            if(run == 1) break;
            reverse(s.begin(), s.end());
        }
        


        
        return ans;
    }
};