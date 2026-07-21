class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, 1e9);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, k});

        dist[k] = 0;

        while (!pq.empty()) {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(time > dist[node])
            {
                continue ;
            }

            for (auto it : adj[node]) {
                int child = it.first;
                int w = it.second;

                if (dist[child] > (w + dist[node])) {
                    dist[child] = w + dist[node];
                    pq.push({dist[child], child});
                }
            }
        }

        int all = -1;
        for (int i = 1; i <= n; i++) {
            all = max(all, dist[i]);
        }

        if (all == 1e9) {
            return -1;
        }

        return all;
    }
};