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
    TreeNode* tree(vector<int>& preorder, vector<int>& inorder,
                   map<int, int>& InorderMap, int p_start, int p_end,
                   int in_start, int in_end) {
        if ((p_start > p_end) || (in_start > in_end)) {
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[p_start]);

        int inpos = InorderMap[preorder[p_start]];
        int nums_left = inpos - in_start;

        node->left = tree(preorder, inorder, InorderMap, p_start + 1,
                          p_start + nums_left, in_start, inpos - 1);

        node->right = tree(preorder, inorder, InorderMap,
                           p_start + nums_left + 1, p_end, inpos + 1, in_end);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> InorderMap;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            InorderMap[inorder[i]] = i;
        }
        TreeNode* root =
            tree(preorder, inorder, InorderMap, 0, n - 1, 0, n - 1);

        return root;
    }
};