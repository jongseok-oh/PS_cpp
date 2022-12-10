import java.util.*;

class Solution {
    public int[] solution(String s) {
        int[] answer = new int[s.length()];
        
        char[] chars = s.toCharArray();
        int cache[] = new int[26];
        
        Arrays.fill(cache, -1);
        
        for(int i =0, len = chars.length; i<len; i++){
            if(cache[chars[i]-'a'] == -1){
                answer[i] = -1;
            }else{
                answer[i] = i - cache[chars[i]-'a'];
            }
            cache[chars[i]-'a'] = i;
        }
        return answer;
    }
}