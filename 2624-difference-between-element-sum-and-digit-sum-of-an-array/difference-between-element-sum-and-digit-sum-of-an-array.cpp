class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n= nums.size();
        int digit_sum = 0;
        int element_sum = 0;

        for(int i=0; i<n; i++)
        {
            element_sum += nums[i];
            int num = nums[i];
            while(num>0)
            {
                int digit = num%10;
                digit_sum += digit;
                num = num/10;
            }
        }
        return abs(digit_sum - element_sum);
    }
};