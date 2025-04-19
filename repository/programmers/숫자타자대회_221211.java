import java.util.*;

class Solution {
    char nums[];
    
    int cost[][] = new int[][]{ { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
                                { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
                                { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
                                { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
                                { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
                                { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
                                { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
                                { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
                                { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
                                { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 }};
    int dp[][][];
    
    int solve(int left, int right, int idx){
        if(idx == nums.length) return 0;
        if(left == right) return 800000;
        if(dp[idx][left][right] != 0) return dp[idx][left][right];
        int tar = nums[idx] - '0';
        return dp[idx][left][right] =
            Math.min(solve(tar, right, idx + 1) + cost[left][tar],
                     solve(left,tar, idx + 1) + cost[right][tar]
                    );
    }
    
    public int solution(String numbers) {
        nums = numbers.toCharArray();
        dp = new int [nums.length][10][10];
        return solve(4,6,0);
    }
}