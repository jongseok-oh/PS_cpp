class Solution {
    public int solution(int[] topping) {
        boolean toppings[] = new boolean[10001];
        
        int cnt[] = new int[topping.length];
        
        int tcnt = 0;
        for(int i =0, len = topping.length; i<len; i++){
            if(toppings[topping[i]] == false){
                tcnt++;
                toppings[topping[i]] = true;
            }
            cnt[i] = tcnt;
        }
        
        int cntrv[] = new int[topping.length];
        toppings = new boolean[10001];
        
        tcnt = 0;
        for(int i =topping.length - 1; i>=0; i--){
            if(toppings[topping[i]] == false){
                tcnt++;
                toppings[topping[i]] = true;
            }
            cntrv[i] = tcnt;
        }
        
        int ans = 0;
        
        for(int i =0, len = topping.length - 1; i<len; i++)
            if(cnt[i] == cntrv[i+1]) ans++;
        
        return ans;
    }
}