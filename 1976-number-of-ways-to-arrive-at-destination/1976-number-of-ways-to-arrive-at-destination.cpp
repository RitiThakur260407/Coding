class Solution {
public:
long long mod = 1e9+7 ;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(n, 1e18), ways(n, 0);
        priority_queue<pair<long long,long long>, vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            pq;

        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            long long dis = pq.top().first;
            long long node = pq.top().second;

            pq.pop();

            if(dis > dist[node])
            {
                continue ;
            }

            for (auto it : adj[node]) {
                int child = it.first;
                int w = it.second;

                if (dist[child] > w + dist[node]) {
                    dist[child] = w + dist[node];
                    ways[child] = ways[node];
                    pq.push({dist[child], child});
                } else if (dist[child] == (w + dist[node])) {
                    ways[child] = (ways[node] + ways[child])%mod;
                }
            }
        }

        return (int)ways[n - 1];
    }
};