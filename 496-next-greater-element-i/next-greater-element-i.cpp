class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> nge(n2);
        unordered_map<int,int> mp;
        stack<int> st;

        for(int i=n2-1; i>=0; i--)
        {
            while(!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }
            if(st.empty()) nge[i] = -1;
            else{
                nge[i] = st.top();
            }
            st.push(nums2[i]);
        }

        for(int i=0; i<n2; i++)
        {
            mp[nums2[i]] = nge[i];
        }

        vector<int> ans;

        for(int m: nums1)
        {
            ans.push_back(mp[m]);
        }
        return ans;   
    }
};