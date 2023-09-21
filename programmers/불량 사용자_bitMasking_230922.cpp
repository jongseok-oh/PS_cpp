#include <string>
#include <vector>

using namespace std;

vector<int> avableMapper[8];

bool canBanned(string userId, string bannedId){
    int n = userId.size(), m = bannedId.size();
    
    if(n != m) return false;
    
    for(int i = 0; i<n; ++i){
        if(bannedId[i] == '*') continue;
        if(bannedId[i] != userId[i]) return false;
    }
    
    return true;
}

bool vVisit[1<<8];

int solve(int banIdx, int visit, int m){
    if(banIdx == m) {
        if(!vVisit[visit]) {
            vVisit[visit] = true;
            return 1;
        }else return 0;
    }
    
    int ret = 0;
    
    for(int& userIdx: avableMapper[banIdx])
        if(!(visit & (1<<userIdx)))
            ret += solve(banIdx + 1, visit | (1<<userIdx), m);
            
    return ret;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    for(int i = 0; i<user_id.size(); ++i)
        for(int j = 0; j<banned_id.size(); ++j)
            if(canBanned(user_id[i], banned_id[j]))
                avableMapper[j].push_back(i);
    
    return solve(0, 0, banned_id.size());
}