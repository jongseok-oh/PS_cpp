class Solution {
    int dy[26], dx[26];

    set<pair<int, int>> visit;
    bool isVisit(int y, int x){
        if(visit.find({y,x}) != visit.end()) return true;
        visit.insert({y,x});
        return false;
    }

public:
    bool isPathCrossing(string path) {
        dy['N' - 'A'] = -1;
        dy['S' - 'A'] = 1;
        dx['E' - 'A'] = 1;
        dx['W' - 'A'] = -1;

        int y = 0, x = 0;
        isVisit(y,x);
        for(char& c: path){
            y += dy[c-'A'], x += dx[c-'A'];
            if(isVisit(y,x)) return true;
        }
        
        return false;
    }
};