class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long  sum =0;
        int n= nums.size();

        for(int i=0; i<n; i++)
        {
            int MAX = INT_MIN , MIN = INT_MAX;
            for(int j=i; j<n ; j++)
            {
                MAX = (nums[j] > MAX)? nums[j] : MAX;
                MIN = (nums[j] < MIN)? nums[j] : MIN;

                sum += (long long)(MAX - MIN);
            }
        }
        return sum ;
    }
};