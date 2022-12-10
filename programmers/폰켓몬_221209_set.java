import java.util.*;

class Solution {
    
    public int solution(int[] nums) {
        Set<Integer> s = new HashSet<>();
        for(int n: nums) s.add(n);
        return Math.min(nums.length/2, s.size());
    }
}