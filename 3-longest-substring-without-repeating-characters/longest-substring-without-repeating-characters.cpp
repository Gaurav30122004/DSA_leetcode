class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = s.size();
        int maxi =0;
        int l=0 , r=0;

        while(r<n)
        {
            while(st.find(s[r]) != st.end())
            {
                st.erase(s[l]);
                l++;
            }

            maxi = max(maxi, r-l+1);
            st.insert(s[r]);
            r++;
        }
        return maxi;

    }
};