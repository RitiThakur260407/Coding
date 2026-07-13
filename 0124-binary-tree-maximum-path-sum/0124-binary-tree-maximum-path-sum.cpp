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
    int PathSum(TreeNode* node, int& maxSum) {
        if (!node)
            return 0;

        int left = max(PathSum(node->left, maxSum),0) ;
        int right = max(PathSum(node->right, maxSum),0);


        int current_sum = node->val + left + right;
        maxSum = max(maxSum, current_sum);

        return node->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;

        PathSum(root, maxSum);

        return maxSum ;
    }
};