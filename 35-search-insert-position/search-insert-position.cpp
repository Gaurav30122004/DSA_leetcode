class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        int st = 0;
        int end = n-1;
        int mid = st + (end-st)/2;

        while(st <= end)
        {
            if(target == nums[mid])
            {
                return mid ;
            }
            else if(target < nums[mid] )
            {
                end = mid-1;
            }
            else {
                st = mid+1;
            }
            mid = st + (end-st)/2;
            
        }

        return st;
    }
};