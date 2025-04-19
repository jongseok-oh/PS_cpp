class Solution {
    public String solution(int[] food) {
        StringBuilder sb = new StringBuilder();
        for(int i = 1, len = food.length; i<len; i++){
            int cnt = food[i]/2;
            while(cnt-->0) sb.append(i);
        }
        StringBuilder rbsb = new StringBuilder(sb);
        return sb.append(0).append(rbsb.reverse()).toString();
    }
}