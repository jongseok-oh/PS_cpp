#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    
    sort(targets.begin(), targets.end(), [](vector<int>& tar1, vector<int>& tar2){
        return tar1[1] < tar2[1];
    });
    
    double pibotEnd = targets[0][1] - 0.1;
    
    for(int i = 1, len = targets.size(); i<len; i++){
        if(pibotEnd <= targets[i][0]){
            pibotEnd = targets[i][1] - 0.1;
            answer++;
        }
    }
        
    return answer;
}