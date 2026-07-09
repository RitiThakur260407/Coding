class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = -1 , f = 0 ;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i++)
        {
            if(f == 0)
            {
                ans = nums[i] ;
                f++ ;
            }
            else
            {
                if(nums[i] == ans)
                {
                    f++ ;
                }
                else
                {
                    f-- ;
                }
            }
        }
        f = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(ans == nums[i]) 
            {
                f++ ;
            }
        }
        if(f > (n/2))
        {
            return ans ;
        }
        return -1 ;
    }
};