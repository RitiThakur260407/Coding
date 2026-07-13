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
    TreeNode* Tree(vector<int>& preorder, vector<int>& inorder,
                   map<int, int>& inorderMap, int p_start, int p_end,
                   int in_start, int in_end) {
        if ((p_start > p_end) || (in_start > in_end))
            return NULL;

        TreeNode* root = new TreeNode(preorder[p_start]);
        int root_index = inorderMap[preorder[p_start]];
        int nums_left = root_index - in_start;

        root->left = Tree(preorder, inorder, inorderMap, p_start + 1,
                          p_start + nums_left, in_start, root_index - 1);

        root->right =
            Tree(preorder, inorder, inorderMap, p_start + nums_left + 1, p_end,
                 root_index + 1, in_end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inorderMap;
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            inorderMap[inorder[i]] = i;
        }

        return Tree(preorder, inorder, inorderMap, 0, n - 1, 0, n - 1);
    }
};