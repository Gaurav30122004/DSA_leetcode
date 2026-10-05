class Solution {
    vector<int> findNSE(vector<int> arr)
    {
        int n= arr.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i= n-1; i>= 0; i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            nse[i] = (st.empty())? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vector<int> arr)
    {
        int n= arr.size();
        vector<int> psee(n);
        stack<int> st;

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            psee[i] = (st.empty())? -1 : st.top();
            st.push(i);
        }
        return psee;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {

        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        long long total =0 , n = arr.size();
        int  MOD = 1e9 +7;

        for(int i=0; i<n; i++)
        {
            int right = nse[i] - i;
            int left = i - psee[i];

            long long contribution = (long long)left * right * arr[i];

            total = (total + contribution) % MOD;
        }
        // int div = pow(10,9) +7;
        return total;

        // int n = arr.size();
        // int total =0;

        // for(int i=0; i<n ; i++)
        // {
        //     int min = INT_MAX;
        //     for(int j=i; j<n; j++)
        //     {
        //         min = (arr[j] < min)? arr[j] : min;
        //         total += min;
        //     }
        // }

        // int div = pow(10,9) +7;
        // return total % div;
    }
};