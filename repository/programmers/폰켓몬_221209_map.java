import java.util.*;

class Solution {
    
    public int solution(int[] nums) {
        Map<Integer, Integer> m = new HashMap<>();
        for(int n: nums) m.put(n,-1);
        return Math.min(nums.length/2, m.size());
    }
}