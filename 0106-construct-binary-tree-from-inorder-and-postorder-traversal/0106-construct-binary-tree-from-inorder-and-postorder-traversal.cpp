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
    TreeNode* tree(vector<int>& inorder, vector<int>& postorder,
                   unordered_map<int, int>& InorderMap, int in_start,
                   int in_end, int post_start, int post_end) {
        if ((in_start > in_end) || (post_start > post_end)) {
            return NULL;
        }

        TreeNode* node = new TreeNode(postorder[post_end]);

        int inpos = InorderMap[postorder[post_end]];
        int nums_left = inpos - in_start;

        node->left = tree(inorder, postorder, InorderMap, in_start, inpos - 1,
                          post_start, post_start + nums_left - 1);

        node->right = tree(inorder, postorder, InorderMap, inpos + 1, in_end,
                           post_start + nums_left, post_end - 1);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> InorderMap;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            InorderMap[inorder[i]] = i;
        }
        return tree(inorder, postorder, InorderMap, 0, n - 1, 0, n - 1);
    }
};