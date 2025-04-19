class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }

        int maxStop = -1;
        for (auto& route : routes) {
            for (int& stop : route) {
                maxStop = max(maxStop, stop);
            }
        }

        if (maxStop < target) {
            return -1;
        }

        int n = routes.size();
        vector<int> minBusesToReach(maxStop + 1, INT_MAX);
        minBusesToReach[source] = 0;

        bool flag = true;
        while (flag) {
            flag = false;
            for (auto& route : routes) {
                int tMin = n+1;
                for (int& stop : route) {
                    tMin = min(tMin, minBusesToReach[stop]);
                }
                tMin++;
                for (int& stop : route) {
                    if (minBusesToReach[stop] > tMin) {
                        minBusesToReach[stop] = tMin;
                        flag = true;
                    }
                }
            }
        }

        return (minBusesToReach[target] < n+1) ? minBusesToReach[target] : -1;
    }
};