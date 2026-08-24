class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // int ans=0;
        // for(int i=0; i<n ; i++)
        // {
        //     ans = ans^nums[i];
        // }
        // return ans ;

        int s =1;
        int e  = n-2;
        int mid = s +(e-s)/2;

        // for array with single element 
        if(n==1)
        {
            return nums[0];
        }
        // explicitely checking if ans is at extremum
        if(nums[0] != nums[1])
        {
            return nums[0];
        }
        if(nums[n-1] != nums[n-2])
        {
            return nums[n-1];
        }
        // npw we dnt have to care abt outof bound overflow of index
        while(s<=e)
        {
            
            if(nums[mid] != nums[mid+1]  && nums[mid] != nums[mid-1])
            {
                return nums[mid];
            }
            if((mid%2 == 0 && nums[mid] == nums[mid+1])  || (mid%2 != 0  && nums[mid] == nums[mid-1]) )
            {
                s = mid+1;
            }
            else
            {
                e= mid-1;
            }
            mid = s +(e-s)/2;

        }
        return -1 ;
    }
};