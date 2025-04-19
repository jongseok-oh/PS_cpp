#include <math.h>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    long long half = 0;
    for(int x = 1; x<=r2; x++){
        int tCnt = 0;
        
        int max_r2_y = sqrt(pow(r2,2) - pow(x, 2));
        
        tCnt += max_r2_y * 2 + 1;
        
        if(x < r1){
            double max_r1_y_doulbe = sqrt(pow(r1,2) - pow(x, 2));
            int max_r1_y_int = max_r1_y_doulbe;
            if(max_r1_y_doulbe == max_r1_y_int) max_r1_y_int--;
            tCnt -= max_r1_y_int * 2 + 1;
        }
        
        half += tCnt;
    }
    
    answer = half * 2;
    int center = (r2 - r1 + 1) * 2;
    
    answer += center;
    
    return answer;
}