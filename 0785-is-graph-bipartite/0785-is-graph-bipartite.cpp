class Solution {
public:
    bool check(int node, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(node);
        color[node] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : graph[node]) {
                if (color[it] == -1) {
                    color[it] = (color[node] == 0) ? 1 : 0;
                    q.push(it);
                } else {
                    if (color[it] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1);

        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                if (!check(i, graph, color)) {
                    return false;
                }
            }
        }

        return true;
    }
};