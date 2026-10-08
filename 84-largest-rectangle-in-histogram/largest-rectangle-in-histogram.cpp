class Solution {

    vector<int> NSE(vector<int> arr)
    {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(st.empty()) nse[i] = n;
            else
            {
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }

    vector<int> PSE(vector<int> arr)
    {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if(st.empty()) pse[i] = -1;
            else
            {
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }

public:
    int largestRectangleArea(vector<int>& heights) {

        long long areaMax = -1;
        int n= heights.size();

        vector<int> nse = NSE(heights);
        vector<int> pse = PSE(heights);

        for(int i=0; i<n; i++)
        {
            long long area = (long long )heights[i]*(nse[i] - pse[i]-1);
            areaMax = max(area,areaMax);
        }

        return areaMax;
        
    }
};