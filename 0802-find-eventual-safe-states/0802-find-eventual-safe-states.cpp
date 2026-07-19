class Solution {
public:
bool cycle(int node , vector<int>& ans , vector<int>& vis , vector<int>& pathvis , vector<vector<int>>& graph)
{
    vis[node] = 1 ;
    pathvis[node] = 1 ;

    for(auto it : graph[node])
    {
        if(vis[it] == 0)
        {
            if(cycle(it,ans,vis,pathvis,graph))
            return true ;
        }
        else
        {
            if(pathvis[it] == 1)
            {
                return true ;
            }
        }
    }
    ans.push_back(node) ;
    pathvis[node] = 0 ;
    return false ;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<int> ans , vis(n,0) , pathvis(n,0) ;
        for(int i = 0 ; i < n ; i++)
        {
            if(vis[i] == 0)
            {
                cycle(i,ans,vis,pathvis,graph) ;
            }
        }
        sort(ans.begin(),ans.end()) ;

        return ans ;
    }
};