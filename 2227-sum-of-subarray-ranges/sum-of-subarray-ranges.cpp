class Solution {
    vector<int> findNSE(vector<int> nums)
    {
        int n= nums.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i= n-1; i>= 0; i--)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            nse[i] = (st.empty())? n : st.top();
            st.push(i);
        }
        return nse;
    }  
    vector<int> findPSEE(vector<int> nums)
    {
        int n= nums.size();
        vector<int> psee(n);
        stack<int> st;

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[st.top()] > nums[i])
            {
                st.pop();
            }
            psee[i] = (st.empty())? -1 : st.top();
            st.push(i);
        }
        return psee;
    }
    vector<int> findNGE(vector<int> nums)
    {
        int n= nums.size();
        stack<int> st;
        vector<int> nge(n);

        for(int i= n-1; i>= 0 ;i--)
        {
            while(!st.empty() && nums[st.top()] <= nums[i])
            {
                st.pop();
            }
            nge[i] = (st.empty())? n : st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int> findPGEE(vector<int> nums)
    {
        int n= nums.size();
        stack<int> st;
        vector<int> pgee(n);

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[st.top()] < nums[i])
            {
                st.pop();
            }
            pgee[i] = (st.empty())? -1 : st.top();
            st.push(i);
        }
        return pgee;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        vector<int> nse = findNSE(nums);
        vector<int> psee = findPSEE(nums);
        vector<int> nge = findNGE(nums);
        vector<int> pgee = findPGEE(nums);

        long long totalMin =0 , n = nums.size();
        long long totalMax =0;

        for(int i=0; i<n; i++)
        {
            int rightNSE = nse[i] - i;
            int leftPSEE = i - psee[i];

            int rightNGE =  nge[i] - i;
            int leftPGEE = i - pgee[i];

            long long contributionMin = (long long)leftPSEE * rightNSE * nums[i];
            totalMin = (totalMin + contributionMin) ;

            long long contributionMax = (long long)leftPGEE * rightNGE* nums[i];
            totalMax = (totalMax + contributionMax) ;

        }
        // int div = pow(10,9) +7;
        return totalMax - totalMin;
    }
};