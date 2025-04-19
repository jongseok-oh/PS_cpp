import java.util.*;

class Solution {
    
    int dy[] = {1,-1,0,0}, dx[] = {0,0,1,-1};
    
    int map[][] = new int[52 * 2][52 * 2];
    
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        for(int[] rect: rectangle){
            
            int x1 = rect[0] * 2;
            int y1 = rect[1] * 2;
            int x2 = rect[2] * 2;
            int y2 = rect[3] * 2;
            
            for(int i = x1; i<=x2; i++){
                map[y1][i] = 1;
                map[y2][i] = 1;
            }
            for(int i = y1; i<=y2; i++){
                map[i][x1] = 1;
                map[i][x2] = 1;
            }
        }
        searchBorder();
        return minDist(new int[]{characterY*2, characterX*2},new int[]{itemY*2, itemX*2});
    }
    
    void searchBorder(){
        Queue<int[]> q = new ArrayDeque<>();
        map[103][103] = 3;
        q.offer(new int[]{103,103});
        List<int[]> border = new ArrayList<>();
        while(!q.isEmpty()){
            int t[] = q.poll();
            for(int dir = 0; dir<4; dir++){
                int ny = t[0] + dy[dir],
                    nx = t[1] + dx[dir];
                
                if(ny <0 || ny>103 || nx <0 || nx >103) continue;
                if(map[ny][nx] == 3 || map[ny][nx] == 2) continue;
                if(map[ny][nx] == 1){
                    border.add(new int[]{ny,nx});
                    map[ny][nx] = 2; continue;
                }
                map[ny][nx] = 3;
                q.offer(new int[]{ny,nx});
            }
        }
        
        // 꼭지점 체크
        boolean chk[][] = new boolean[52*2][52*2];
        
        for(int[] t: border){
            for(int dir = 0; dir<4; dir++){
                int ny = t[0] + dy[dir],
                    nx = t[1] + dx[dir];
                
                if(ny <0 || ny>103 || nx <0 || nx >103) continue;
                if(map[ny][nx] == 1){
                    if(chk[ny][nx] == true) map[ny][nx] = 2;
                    else chk[ny][nx] = true;
                }
            }
        }
    }
    
    int minDist(int[] character, int[] item){
        Queue<int[]> q = new ArrayDeque<>();
        map[character[0]][character[1]] = 3;
        q.offer(character);
        int ans = 0;
        while(!q.isEmpty()){
            int qsize = q.size();
            while(qsize-->0){
                int t[] = q.poll();
                if(t[0] == item[0] && t[1] == item[1]) return ans/2;
                for(int dir = 0; dir<4; dir++){
                    int ny = t[0] + dy[dir],
                        nx = t[1] + dx[dir];
                    if(map[ny][nx] != 2) continue;
                    map[ny][nx] = 3;
                    q.offer(new int[]{ny,nx});
                }
            }
            ans++;
        }
        return -1;
    }
}