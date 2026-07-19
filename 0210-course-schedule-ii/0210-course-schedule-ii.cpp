class Solution {
public:
bool dfs(int node , vector<int>& vis , vector<int>& pathvis , stack<int>& st , vector<vector<int>>& adj)
{
    vis[node] = 1 ;
    pathvis[node] = 1 ;

    for(auto it : adj[node])
    {
        if(vis[it] == 0)
        {
            if(dfs(it,vis,pathvis,st,adj))
            {
                return true ;
            }
        }
        else
        {
            if(pathvis[it] == 1)
            return true ;
        }
    }
    st.push(node) ;
    pathvis[node] = 0 ;
    return false ;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses) ;
        for(int i = 0 ; i < prerequisites.size() ; i++)
        {
            int u = prerequisites[i][0] ;
            int v = prerequisites[i][1] ;
            adj[v].push_back(u) ;
        }
        vector<int> vis(numCourses,0) , pathvis(numCourses,0) ;
        stack<int> st ;

        for(int i = 0 ; i < numCourses ; i++)
        {
            if(vis[i] == 0)
            {
                if(dfs(i,vis,pathvis,st,adj))
                {
                    return {} ;
                }
            }
        } 
        vector<int> ans ;
        while(!st.empty())
        {
            ans.push_back(st.top()) ;
            st.pop() ;
        }
        return ans ;
    }
};