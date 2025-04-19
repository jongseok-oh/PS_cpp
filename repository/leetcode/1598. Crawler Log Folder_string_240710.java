class Solution {
    public int minOperations(String[] logs) {
        int depth = 0;
        for(String log : logs){
            if(log.startsWith("..")){
                if(depth > 0) --depth;
            }else if(log.charAt(0) != '.') ++depth;
        }
        return depth;
    }
}