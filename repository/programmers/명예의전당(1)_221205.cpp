#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer(score.size());
    
    priority_queue<int> q;
    for(int i =0, len = score.size(); i<len; i++){
        q.push(-score[i]);
        if(q.size()>k) q.pop();
        answer[i] = -q.top();
    }
    return answer;
}