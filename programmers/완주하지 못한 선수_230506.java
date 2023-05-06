import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        Map<String, Integer> map = new HashMap<>();
        
        for(String com: completion){
            if(map.containsKey(com)) map.put(com, map.get(com) + 1);
            else map.put(com, 1);
        }
        
        for(String par : participant){
            if(!map.containsKey(par) || map.get(par) == 0) return par;
            else map.put(par, map.get(par) - 1);
        }
        
        return "";
    }
}