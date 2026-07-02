/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parent ;
        queue<TreeNode*> q ;
        q.push(root) ;
        while(!q.empty())
        {
            TreeNode* node = q.front() ;
            q.pop() ;

            if(node->left)
            {
                q.push(node->left) ;
                parent[node->left] = node ;
            }
            if(node->right)
            {
                q.push(node->right) ;
                parent[node->right] = node ;
            }
        }
        queue<pair<TreeNode*,int>> q1 ;
        q1.push({target,0}) ;
        vector<int> ans ;
        map<TreeNode*,int> visited ;
        visited[target]++ ;

        while(!q1.empty())
        {
            TreeNode* node = q1.front().first ;
            int dist = q1.front().second ;
            q1.pop() ;

            if(dist == k)
            {
                ans.push_back(node->val) ;
            }
            
            if(node -> left && (visited.find(node->left) == visited.end()))
            {
                q1.push({node->left,dist+1}) ;
                visited[node->left]++ ;
            }
            if(node->right && (visited.find(node->right) == visited.end()))
            {
                q1.push({node->right,dist+1}) ;
                visited[node->right]++ ;
            }
            if(parent.find(node) != parent.end() && (visited.find(parent[node]) == visited.end()))
            {
                q1.push({parent[node],dist+1}) ;
                visited[parent[node]]++ ;
            }
        }
        return ans ;
    }
};