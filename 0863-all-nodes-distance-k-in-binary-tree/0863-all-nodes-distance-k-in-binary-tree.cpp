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
        if((!root) || (!target))
        return {} ;
        
        map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        queue<pair<TreeNode*, int>> q1;
        map<TreeNode*, int> visited;
        vector<int> ans;
        visited[target]++;
        q1.push({target, 0});

        while (!q1.empty()) {
            TreeNode* node = q1.front().first;
            int dist = q1.front().second;
            q1.pop();

            if (dist == k) {
                ans.push_back(node->val);
            }

            if ((node->left) && (visited.find(node->left) == visited.end())) {
                q1.push({node->left, dist + 1});
                visited[node->left]++ ;
            }
            if ((node->right) && (visited.find(node->right) == visited.end())) {
                q1.push({node->right, dist + 1});
                visited[node->right]++ ;
            }
            if (parent[node] &&
                (visited.find(parent[node]) == visited.end())) {
                q1.push({parent[node], dist + 1});
                visited[parent[node]]++ ;
            }
        }

        return ans;
    }
};