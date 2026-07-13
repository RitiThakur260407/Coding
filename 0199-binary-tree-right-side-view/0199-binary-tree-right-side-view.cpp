/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
        {
            return {} ;
        }
        queue<pair<int, TreeNode*>> q;
        map<int, int> mpp;
        q.push({0, root});

        while (!q.empty()) {
            int row = q.front().first;
            TreeNode* node = q.front().second;
            q.pop();

            mpp[row] = node->val;

            if (node->left) {
                q.push({row + 1, node->left});
            }
            if (node->right) {
                q.push({row + 1, node->right});
            }
        }

        vector<int> ans;
        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};