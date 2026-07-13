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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        long long maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            long long mini = LLONG_MAX, maxi = LLONG_MIN;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                long long count = q.front().second;
                q.pop();

                mini = min(mini, count);
                maxi = max(maxi, count);

                long long width = maxi-mini ;

                if (node->left) {
                    q.push({node->left, 2 * width});
                }
                if (node->right) {
                    q.push({node->right, 2 * width + 1});
                }
            }

            maxWidth = max(maxWidth, (maxi - mini + 1));
        }

        return maxWidth;
    }
};