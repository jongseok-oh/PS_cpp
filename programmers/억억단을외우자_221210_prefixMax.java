import java.util.*;
class Solution {
    public int[] solution(int e, int[] starts) {
        int cnt[] = new int[e+1];
        
        for(int i =1; i<=e; i++){
            for(int j = 1; j<=e/i; j++){
                cnt[i*j]++;
            }
        }
        int prefix[][] = new int[e+1][];
        prefix[e] = new int[]{e,cnt[e]};
        
        for(int i = e - 1; i>=1; i--){
            if(cnt[i] > prefix[i+1][1]){
                prefix[i] = new int[]{i,cnt[i]};
            }else if(cnt[i] < prefix[i+1][1]){
                prefix[i] = prefix[i+1];
            }else{
                prefix[i] = (prefix[i+1][0] > i ? new int[]{i,cnt[i]}:prefix[i+1]);
            }
        }
        int ans[] = new int[starts.length];
        for(int i =0, len = starts.length; i<len; i++){
            ans[i] = prefix[starts[i]][0];
        }
        return ans;
    }
}