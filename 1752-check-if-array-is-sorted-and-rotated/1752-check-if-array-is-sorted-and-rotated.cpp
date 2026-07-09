class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size() ;
        bool check = true ;
        for(int i = 1 ; i < n ; i++)
        {
            if(nums[i] < nums[i-1])
            {
                if(check == true)
                {
                    check = false ;
                }
                else
                {
                    return false ;
                }
            }
        }
        if(nums[n-1] > nums[0])
        {
            if(check == false)
            {
                return false ;
            }
        }
        return true ;
    }
};