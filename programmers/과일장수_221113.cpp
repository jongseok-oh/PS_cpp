#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int n = score.size();
    sort(score.begin(), score.end(), greater<int>());
    int i =0;
    while(true){
        if(i + m - 1 >=n)break;
        
        answer += score[i+m-1] * m;
        i += m;
    }
    
    return answer;
}