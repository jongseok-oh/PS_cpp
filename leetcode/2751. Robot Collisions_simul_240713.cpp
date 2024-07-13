class Solution {
    struct Robot{
        int p, h, idx;
    };

    vector<int> live2ret(vector<Robot>& live){
        sort(live.begin(), live.end(), [](auto& r1, auto r2){
            return r1.idx < r2.idx;
        });
        vector<int> ret;
        for(auto& r : live) ret.push_back(r.h);
        return ret;
    }
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        auto cmp1 = [](auto& r1, auto& r2){return r1.p > r2.p;};
        auto cmp2 = [](auto& r1, auto& r2){return r1.p < r2.p;};
        set<Robot, decltype(cmp1)> right;
        set<Robot, decltype(cmp2)> left;

        for(int i = 0, n = healths.size(); i<n; ++i){
            if(directions[i] == 'R') right.insert({positions[i], healths[i], i});
            else left.insert({positions[i], healths[i], i});
        }
        
        vector<Robot> live;
        if(!right.size()) {
            live.assign(left.begin(), left.end());
            return live2ret(live);
        }
        
        while(right.size()){
            auto it = right.begin();
            auto lit = left.upper_bound({it->p, 0, 0});
            if(left.end() == lit){
                live.push_back(*it);
                right.erase(it);
            }else {
                if(it->h > lit->h){
                    auto t = *it; t.h--;
                    right.erase(it); right.insert(t);
                    left.erase(lit);
                }else if(it->h == lit->h){
                    right.erase(it);
                    left.erase(lit);
                }else{
                    auto t = *lit; t.h--;
                    left.erase(lit); left.insert(t);
                    right.erase(it);
                }
            }
        }
        for(auto& t : left) live.push_back(t);
        return live2ret(live);
    }
};