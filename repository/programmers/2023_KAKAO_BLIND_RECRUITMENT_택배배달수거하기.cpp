#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int end = -1;
    for(int i =0,len = deliveries.size(); i<len; i++)
        if(deliveries[i] || pickups[i]) end = i;
    
    int delIdx = end, pickIdx = end;
    while(delIdx>=0 || pickIdx>=0){
        answer += (max(delIdx,pickIdx) + 1) * 2;
        int tdel = cap, tpick = cap;

        while(delIdx>=0){
            if(tdel - deliveries[delIdx] <0){
                deliveries[delIdx] -= tdel;
                break;
            }
            tdel -= deliveries[delIdx--];
        }
        
        while(pickIdx>=0){
            if(tpick - pickups[pickIdx] <0){
                pickups[pickIdx] -= tpick; break;
            }
            tpick -= pickups[pickIdx--];
        }
    }
    
    return answer;
}