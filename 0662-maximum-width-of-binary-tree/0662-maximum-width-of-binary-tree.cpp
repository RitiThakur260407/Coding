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
        long long maxWidth = 0;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long long start = q.front().second , last = 0, width = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                long long index = q.front().second;
                q.pop();

                start = min(start,index) ;
                last = max(last,index) ;
                width = last-start+1 ;
                maxWidth = max(maxWidth,width) ;

                if(node->left)
                {
                    q.push({node->left,2*width}) ;
                }
                if(node->right)
                {
                    q.push({node->right,2*width+1}) ;
                }
            }
        }
        return (int)maxWidth ;
    }
};