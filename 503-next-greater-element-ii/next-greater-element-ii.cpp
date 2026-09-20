class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans(n) ;

        if (n==1)
        {
            return {-1} ;
        }

        for(int i=0; i<n ; i++)
        {
            for(int j=i+1; j<n+i; j++)
            {
                if(nums[j%n] > nums[i])
                {
                    ans[i] = nums[j%n];
                    break;
                }
                ans[i] = -1;
            }
        }
        return ans ;
    }
};