import java.util.*;
class Solution {
    
    String cells[][] = new String[51][51];
    int parent[][][] = new int[51][51][2];
    
    int[] getParent(int r, int c){
        if(parent[r][c][0] == 0 && parent[r][c][1] == 0) return new int[] {r,c};
        return parent[r][c] = getParent(parent[r][c][0], parent[r][c][1]);
    }
    
    void merge(int r1, int c1, int r2, int c2){
        if(r1 == r2 && c1 == c2) return;
        int p1[] = getParent(r1,c1);
        int p2[] = getParent(r2,c2);
        if(p1[0] == p2[0] && p1[1] == p2[1]) return;
        
        if(cells[p1[0]][p1[1]].equals("EMPTY"))
            parent[p1[0]][p1[1]] = p2;
        else parent[p2[0]][p2[1]] = p1;
    }
    
    public String[] solution(String[] commands) {
        List<String> ans = new ArrayList<>();
        for(int i =1; i<=50; i++) for(int j =1; j<=50; j++)
            cells[i][j] = "EMPTY";
        
        StringTokenizer st;
        for(String command: commands){
            st = new StringTokenizer(command);
            String com = st.nextToken();
            if(com.equals("UPDATE")){
                String coms[] = new String[2];
                for(int i =0; i<2; i++) coms[i] = st.nextToken();
                if(st.hasMoreTokens()){
                    int[] p = getParent(Integer.parseInt(coms[0]),
                                        Integer.parseInt(coms[1]));
                    cells[p[0]][p[1]] = st.nextToken();
                }else{
                    for(int i = 1; i<=50; i++) for(int j =1; j<=50; j++){
                        int[] p = getParent(i,j);
                        if(cells[p[0]][p[1]].equals(coms[0]))
                            cells[p[0]][p[1]] = coms[1];
                    }
                }
            }else if(com.equals("MERGE")){
                int loc[] = new int[4];
                for(int i =0; i<4; i++) loc[i] = Integer.parseInt(st.nextToken());
                merge(loc[0], loc[1], loc[2], loc[3]);
            }else if(com.equals("UNMERGE")){
                int loc[] = new int[2];
                for(int i =0; i<2; i++) loc[i] = Integer.parseInt(st.nextToken());
                int p[] = getParent(loc[0], loc[1]);
                String value = cells[p[0]][p[1]];
                List<int[]> mergedCells = new ArrayList<>();
                for(int i =1; i<=50; i++) for(int j =1; j<=50; j++){
                    int tp[] = getParent(i, j);
                    if(tp[0] == p[0] && tp[1] == p[1])
                    {
                        mergedCells.add(new int[]{i,j});
                    }
                }
                for(int [] tloc: mergedCells){
                    parent[tloc[0]][tloc[1]] = new int[]{0,0};
                    cells[tloc[0]][tloc[1]] = "EMPTY";
                }
                cells[loc[0]][loc[1]] = value;
            }else{
                int loc[] = new int[2];
                for(int i =0; i<2; i++) loc[i] = Integer.parseInt(st.nextToken());
                int p[] = getParent(loc[0], loc[1]);
                ans.add(cells[p[0]][p[1]]);
            }
        }
        return ans.toArray(new String[0]);
    }
}