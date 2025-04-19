class Solution {
    
    int a,b;
    
    int getCoke(int n){
        if(n < a) return 0;
        return getCoke(n/a * b + n % a) + n/a * b;
    }
    
    public int solution(int _a, int _b, int n) {
        a = _a; b = _b;
        return getCoke(n);
    }
}