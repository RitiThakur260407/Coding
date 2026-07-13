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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<int, pair<int, TreeNode*>>> q;
        map<int, map<int, multiset<int>>> mpp;

        q.push({0, {0, root}});

        while (!q.empty()) {
            int col = q.front().first;
            int row = q.front().second.first;
            TreeNode* node = q.front().second.second;
            q.pop();

            mpp[col][row].insert(node->val);

            if (node->left) {
                q.push({col - 1, {row + 1, node->left}});
            }
            if (node->right) {
                q.push({col + 1, {row + 1, node->right}});
            }
        }

        for (auto it : mpp) {
            vector<int> level;
            for (auto p : it.second) {
                for (auto q : p.second) {
                    level.push_back(q);
                }
            }
            ans.push_back(level);
        }

        return ans;
    }
};