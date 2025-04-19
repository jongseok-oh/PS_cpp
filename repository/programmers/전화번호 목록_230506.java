import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        Arrays.sort(phone_book);
        
        for(int i = 1, len = phone_book.length; i<len; i++)
            if(phone_book[i].startsWith(phone_book[i-1])) return false;
        
        return true;
    }
}