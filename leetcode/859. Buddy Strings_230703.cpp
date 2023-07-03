class Solution {
    int alCnt[26];
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        int n = s.size();
        
        char diffS = 'A', diffG = 'A';
        int swapCnt = 0;
        for(int i = 0; i<n; i++){
            alCnt[s[i] - 'a']++;
            
            if(s[i] != goal[i]){
                if(diffS == 'A'){
                    diffS = s[i];
                    diffG = goal[i];
                }else{
                    // 이미 한 번 스왑함
                    if(swapCnt) return false;
                    
                    // 스왑이 불가능함
                    if(goal[i] != diffS || s[i] != diffG) return false;
                    swapCnt++;
                }
            }
        }

        if(diffS != 'A' && !swapCnt) return false;

        // 둘이 똑같이 생겼으면
        if(!swapCnt){
            for(int i = 0; i<26; i++) if(alCnt[i] >= 2) return true;
            return false;
        }
        return true;
    }
};