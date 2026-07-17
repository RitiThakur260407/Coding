class Solution {
public:
    void bfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
        queue<int> q ;
        q.push(node) ;
        visited[node] = 1 ;

        while(!q.empty())
        {
            int curr = q.front() ;
            q.pop() ;

            for(auto it : adj[curr])
            {
                if(visited[it] == 0)
                {
                    q.push(it) ;
                    visited[it] = 1 ;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (isConnected[i][j] == 1) {
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int count = 0;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                bfs(i, visited, adj);
                count++;
            }
        }
        return count;
    }
};