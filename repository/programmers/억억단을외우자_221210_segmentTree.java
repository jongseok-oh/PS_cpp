import java.util.*;
class Solution {
    
    int tree[];
    int cnt[];
    
    // 몇 번 등장했는지를 return type에 저장할 필요가 없다.
    // cnt array에서 그때 그때 참조해서 쓰면 됨
    // starts[i] ~ e 단위의 고정된 end point이므로 segment tree가 더 느림
    
    int init(int left, int right, int node){
        if(left == right) return tree[node] = left;
        int mid = (left+right) >>1;
        int n1 = init(left, mid, node *2);
        int n2 = init(mid+1, right, node *2 + 1);
        
        if(cnt[n1] > cnt[n2]) return tree[node] = n1;
        else if(cnt[n1] < cnt[n2]) return tree[node] = n2;
        else{
            return tree[node] = Math.min(n1,n2);
        }
    }
    
    int getMax(int start, int end, int node, int left, int right){
        if(start > right || end < left) return 0;
        if(left <= start && right >= end) return tree[node];
        
        int mid = (start + end) >> 1;
        int n1 = getMax(start, mid, node * 2, left, right);
        int n2 = getMax(mid+1, end, node * 2 + 1, left, right);
        if(cnt[n1] > cnt[n2]) return n1;
        else if(cnt[n1] < cnt[n2]) return n2;
        else{
            return Math.min(n1,n2);
        }
    }
    
    public int[] solution(int e, int[] starts) {
        cnt = new int[e+1];
        cnt[0] = -1;
        for(int i =1; i<=e; i++){
            for(int j = 1; j<=e/i; j++){
                cnt[i*j]++;
            }
        }
        
        tree = new int [(e+1)*4];
        init(1,e,1);
        
        int ans[] = new int[starts.length];
        for(int i =0, len = starts.length; i<len; i++){
            ans[i] = getMax(1,e,1,starts[i],e);
        }
        return ans;
    }
}