class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() ;
        int count = 1 ;
        sort(nums.begin(),nums.end()) ;
        for(int i = 1 ; i < n ; i++)
        {
            if(nums[i-1] == nums[i])
            {
                count++ ;
            }
            else
            {
                if(count > (n/2))
                {
                    return nums[i-1] ;
                }
                count = 1 ;
            }
        }
        if(count > n/2)
        {
            return nums[n-1] ;
        }
        return -1 ;
    }
};