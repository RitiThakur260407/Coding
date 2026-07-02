/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void dfs(TreeNode* node , int& count)
{
    if(node == NULL)
    {
        return ;
    }
    count++ ;
    dfs(node->left,count) ;
    dfs(node->right,count) ;
}
    int countNodes(TreeNode* root) {
        int count = 0 ;
        dfs(root,count) ;
        return count ;
    }
};