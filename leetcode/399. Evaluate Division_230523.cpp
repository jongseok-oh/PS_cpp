class Solution {
    struct Pair{
        string str;
        double value;
    };
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<Pair>> graph;

        for(int i = 0; i<equations.size(); i++){
            string& a = equations[i][0];
            string& b = equations[i][1];

            double v = values[i];

            graph[a].push_back({b, v});
            graph[b].push_back({a, 1.0 / v});
        }

        vector<double> ret;
        for(auto& q: queries){
            string& a = q[0];
            string& b = q[1];

            if(graph.find(a) == graph.end()){
                ret.push_back(-1.0);
            }else ret.push_back(bfs(graph, a, b));
        }

        return ret;
    }

    double bfs(unordered_map<string, vector<Pair>>& graph, string& start, string& end){
        queue<Pair> q;
        set<string> visit;

        q.push({start, 1.0});
        visit.insert(start);
        
        while(q.size()){
            string t = q.front().str;
            double v = q.front().value;

            if(t == end) return v;

            q.pop();
            
            for(auto& next: graph[t]){
                if(visit.find(next.str) != visit.end()) continue;
                visit.insert(next.str);
                q.push({next.str, v * next.value});
            }
        }
        return -1.0;
    }
};