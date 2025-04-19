import java.util.*;

class Solution {
    
    public int solution(int[] nums) {
        int answer = nums.length/2;
        
        Integer types[] = new Integer[200001];
        Arrays.fill(types, 0);
        for(int nn: nums){
            types[nn]++;
        }
        
        Arrays.sort(types, (i1,i2)->i2-i1);
        
        int i = 0;
        while(types[i] != 0)i++;
        
        return Math.min(answer, i);
    }
}