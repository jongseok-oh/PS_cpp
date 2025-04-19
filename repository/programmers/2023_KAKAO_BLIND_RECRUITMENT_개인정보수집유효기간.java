import java.util.*;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        StringTokenizer st = new StringTokenizer(today,".");
        int tY = Integer.parseInt(st.nextToken());
        int tM = Integer.parseInt(st.nextToken());
        int tD = Integer.parseInt(st.nextToken());
        
        int termArr[] = new int[30];
        
        for(String term: terms){
            st = new StringTokenizer(term);
            termArr[st.nextToken().charAt(0) - 'A'] = Integer.parseInt(st.nextToken());
        }
        
        List<Integer> ansList = new ArrayList<>();
        for(int i = 0, len = privacies.length; i<len ;i++){
            st = new StringTokenizer(privacies[i]);
            String date = st.nextToken();
            int termIdx = st.nextToken().charAt(0) - 'A';
            
            st = new StringTokenizer(date,".");
            int year = Integer.parseInt(st.nextToken());
            int month = Integer.parseInt(st.nextToken());
            int day = Integer.parseInt(st.nextToken());
            
            year += (month + termArr[termIdx]-1)/12;
            month = (month + termArr[termIdx]-1) % 12 + 1;
            
            boolean flag = false;
           
            if(tY > year) flag = true;
            else if(year == tY){
                if(month < tM) flag= true;
                else if(month == tM){
                    if(day - 1 < tD) flag= true;
                }
            }
            if(flag) ansList.add(i+1);
        }
        
        int ans[] = new int[ansList.size()];
        
        for(int i =0; i<ans.length; i++) ans[i] = ansList.get(i);
        
        return ans;
    }
}