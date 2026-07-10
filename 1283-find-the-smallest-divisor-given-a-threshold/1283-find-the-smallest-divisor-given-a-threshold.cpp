class Solution {
public:
long long result(vector<int>& nums , long long divisor)
{
    long long ans = 0 ;
    for(int i = 0 ; i < nums.size() ; i++)
    {
        ans += (nums[i] + divisor -1)/divisor ;
    }
    return ans ;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size() ;
        long long low = 1 , high = *max_element(nums.begin(),nums.end()) , divisor ;
        while(low <= high)
        {
            long long mid = low + (high-low)/2 ;
            long long ans = result(nums,mid) ;

            if(ans <= threshold)
            {
                divisor = mid ;
                high = mid -1 ;
            }
            else
            {
                low = mid+1 ;
            }
        }
        return divisor ;
    }
};