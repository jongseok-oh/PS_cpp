class Solution {
    struct Ticket{
        string end;
        int idx;
    };

    bool solve(int order, string t, int n,
    unordered_map<string, vector<Ticket>>& graph, vector<vector<string>>& tickets,
    vector<string>& ans, vector<bool>& visit){
        ans[order] = t;
        if(order == n) return true;

        for(auto& next: graph[t]){
            if(!visit[next.idx]){
                visit[next.idx] = true;
                if(solve(order+1, next.end, n, graph, tickets, ans, visit)) return true;
                visit[next.idx] = false;
            }
        }

        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<Ticket>> graph;
        int n = tickets.size();

        for(int i = 0; i<n; i++){
            vector<string>& tick = tickets[i];
            graph[tick[0]].push_back({tick[1], i});
        }

        for(auto it = graph.begin(); it != graph.end(); ++it){
            auto& vec = it->second;
            sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){
                return a.end < b.end; 
            });
        }

        vector<string> ans(n+1);
        vector<bool> visit(n);

        solve(0, "JFK", n, graph, tickets, ans, visit);

        return ans;
    }
};