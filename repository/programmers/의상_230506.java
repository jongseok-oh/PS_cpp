import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        
        Map<String, Integer> map = new HashMap<>();
        
        for(String [] cl: clothes){
            String comp = cl[1];
            
            if(map.containsKey(comp)) map.put(comp, map.get(comp) + 1);
            else map.put(comp,1);
        }
        
        int ans = 1;
        
        for(Map.Entry<String, Integer> entry : map.entrySet())
            ans *= entry.getValue() + 1;
        
        return ans-1;
    }
}