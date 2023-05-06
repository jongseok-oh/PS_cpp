import java.util.*;

class Solution {
    public int solution(int[] nums) {
        
        Set<Integer> m = new HashSet<>();
        
        for(int num: nums) m.add(num);
        
        return Math.min(m.size(), nums.length/2);
    }
}