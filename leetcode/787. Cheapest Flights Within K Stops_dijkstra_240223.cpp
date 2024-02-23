class Solution {
    struct Info{int node, price, k;};
    vector<pair<int,int>> con[100];
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(auto& flight: flights){
            int from = flight[0], to = flight[1], price = flight[2];
            con[from].push_back({price, to});
        }
        vector<vector<int>> dist(n, vector<int>(k + 3, 1e9));

        auto cmp = [](Info& a, Info& b){
            return a.price > b.price;
        };

        priority_queue<Info, vector<Info>, decltype(cmp)> q;
        
        q.push({src, 0, 0});
        dist[src][0] = 0;

        while(q.size()){
            auto [node, price, tk] = q.top(); q.pop();

            if(node == dst) return price;
            if(tk > k || price > dist[node][tk]) continue;

            for(auto [cost, nNode] : con[node]){
                int nPrice = price + cost;

                if(dist[nNode][tk + 1] > nPrice){
                    dist[nNode][tk + 1] = nPrice;
                    q.push({nNode, nPrice, tk + 1});
                }
            }
        }
        return -1;
    }
};