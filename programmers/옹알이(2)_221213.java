class Solution {
    public int solution(String[] babbling) {
        int answer = 0;
        
        String bab[] = new String[]{"aya", "ye", "woo", "ma"};
        
        for(String ba: babbling){
            int past = -1;
            
            boolean correct = true;
            
            loof:
            for(int i = 0,len = ba.length(); i<len; ){
                boolean chk = false;
                for(int j =0; j<4; j++){
                    if(ba.substring(i, Math.min(ba.length(), i + bab[j].length())).equals(bab[j])){
                        if(past == j){
                            correct = false;
                            break loof;
                        }
                        i += bab[j].length();
                        past = j;
                        chk = true;
                        break;
                    }
                }
                if(!chk){
                    correct = false; break;
                }
            }
            if(correct) answer++;
        }
        
        return answer;
    }
}