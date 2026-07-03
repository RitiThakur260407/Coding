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
void helper(TreeNode* root , vector<int>& inorder)
{
    if(root == NULL)
    {
        return ;
    }
    helper(root->left,inorder) ;
    inorder.push_back(root->val) ;
    helper(root->right,inorder) ;
}
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> inorder ;
        helper(root,inorder) ;
        vector<vector<int>> answer(queries.size()) ;

        for(int i = 0 ; i < queries.size() ; i++)
        {
            int x = queries[i] ;
            int mini = INT_MIN , maxi = INT_MAX ;
            int low = 0 , high = inorder.size()-1 ;

            while(low <= high)
            {
                int mid = low + (high-low)/2 ;
                if(inorder[mid] <= x)
                {
                    mini = max(mini,inorder[mid]) ;
                    low = mid+1 ;
                }
                else
                {
                    high = mid-1 ;
                }
            }
            if(mini == INT_MIN)
            {
                mini = -1 ;
            }

            low = 0 , high = inorder.size()-1 ;

            while(low <= high)
            {
                int mid = low + (high-low)/2 ;
                if(inorder[mid] >= x)
                {
                    maxi = min(maxi,inorder[mid]) ;
                    high = mid-1 ;
                }
                else
                {
                    low = mid+1 ;
                }
            }
            if(maxi == INT_MAX)
            {
                maxi = -1 ;
            }
            answer[i] = {mini,maxi} ;
        }
        return answer ;
    }
};