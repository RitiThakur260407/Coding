class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v, w});
        }

        vector<int> cost(n, 1e9);
        queue<pair<int, int>> q;

        q.push({src, 0});
        cost[src] = 0;
        int stops = 0;

        while (!q.empty()) {
            if (stops > k) {
                break;
            }

            int size = q.size();

            for (int i = 0; i < size; i++) {
                int node = q.front().first;
                int costVal = q.front().second;
                q.pop();

                for (auto it : adj[node]) {
                    int neighbour = it.first;
                    int value = it.second;

                    if (cost[neighbour] > (value + costVal)) {
                        cost[neighbour] = value + costVal;
                        q.push({neighbour, cost[neighbour]});
                    }
                }
            }

            stops++;
        }

        if (cost[dst] == 1e9) {
            return -1;
        }

        return cost[dst];
    }
};