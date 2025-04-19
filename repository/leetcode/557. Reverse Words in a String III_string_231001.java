class Solution {
    public String reverseWords(String s) {
        StringBuilder sb = new StringBuilder();

        String strs[] = s.split(" ");

        for(int i = 0; i<strs.length; ++i){
            for(int j = strs[i].length() -1; j>=0; --j)
                sb.append(strs[i].charAt(j));
            if(i != strs.length - 1) sb.append(' ');
        }

        return sb.toString();
    }
}