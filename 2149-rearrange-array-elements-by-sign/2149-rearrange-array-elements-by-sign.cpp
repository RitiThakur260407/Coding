class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos , neg , ans;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] >= 0)
            {
                pos.push_back(nums[i]) ;
            }
            else
            {
                neg.push_back(nums[i]) ;
            }
        }
        int i = 0 ;
        while(i < n)
        {
            ans.push_back(pos[i/2]) ;
            ans.push_back(neg[i/2]) ;
            i += 2 ;
        }
        return ans ;
    }
};