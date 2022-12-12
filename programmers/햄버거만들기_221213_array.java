import java.util.*;

// 너무 좋은 풀이
// 진짜 stack을 쓰면 top 값을 확인하고 pop하고
// 복원 하는 작업이 필요했는데 배열을 사용해
// indexing으로 앞에 네개를 확인 할 수 있음

class Solution {
    public int solution(int[] ing) {
        int stack[] = new int[ing.length];
        int st = 0, ans = 0;
        for(int i: ing){
            stack[st++] = i;
            if(st>=4 && stack[st -4] == 1
              && stack[st -3] == 2
              && stack[st -2] == 3
              && stack[st -1] == 1){
                ans++; st-=4;
            }
        }
        return ans;
    }
}