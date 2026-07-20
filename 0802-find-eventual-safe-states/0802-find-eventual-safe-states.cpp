class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0), check(n,0) , ans;
        queue<int> q;

        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                adj[it].push_back(i);
                indegree[i]++;
            }

            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            check[node] = 1 ;

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        for(int i = 0 ; i < n ; i++)
        {
            if(check[i] == 1)
            {
                ans.push_back(i) ;
            }
        }
        return ans;
    }
};