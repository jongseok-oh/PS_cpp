class Solution { 
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }
    
    public int solution(int[] arrayA, int[] arrayB) {
        int answer = 0;
        
        int gcdA = arrayA[0];
        for(int i = 1, len = arrayA.length; i<len; i++)
            gcdA = gcd(gcdA, arrayA[i]);
        
        int gcdB = arrayB[0];
        for(int i = 1, len = arrayB.length; i<len; i++)
            gcdB = gcd(gcdB, arrayB[i]);
        
        for(int i = 0, len = arrayB.length; i<len; i++)
            if(arrayB[i] % gcdA == 0){gcdA = 0; break;}
        
        for(int i = 0, len = arrayA.length; i<len; i++)
            if(arrayA[i] % gcdB == 0){gcdB = 0; break;}
        
        return Math.max(gcdA, gcdB);
    }
}