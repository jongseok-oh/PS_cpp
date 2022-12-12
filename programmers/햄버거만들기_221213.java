import java.util.*;
class Solution {
    public int solution(int[] ing) {
        int len = ing.length;
        
        Stack<Integer> st = new Stack<>();
        
        int ans = 0;
        
        int ingChk[] = new int[]{1,3,2,1};
        
        for(int i =0; i<len; i++){
            st.push(ing[i]);
            if(st.size()>=4 && st.peek() == 1){
                int j = 0; boolean find = true;
                for(; j<4; j++){
                    if(ingChk[j] != st.peek())
                    {
                        find = false; break;
                    }
                    st.pop();
                }
                if(find){
                    ans++;
                }
                else{
                    for(int k = j - 1; k>=0; k--) st.push(ingChk[k]);
                }
            }
        }
        return ans;
    }
}