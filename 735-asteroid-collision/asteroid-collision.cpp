class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st ;
        int n= asteroids.size();

        for(int i=0; i<n; i++)
        {
            if(asteroids[i] < 0)
            {
                while(!st.empty() && st.top() >0 && st.top() < abs(asteroids[i]))
                {
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(asteroids[i]))
                {
                    st.pop();
                    continue;
                }
                if(st.empty() || st.top() < 0)
                {
                    st.push(asteroids[i]);
                }
            }
            else
            {
                st.push(asteroids[i]);
            }
        }
        int m = st.size();
        vector<int> ans(m);
        for(int i= m-1 ; i>= 0; i--)
        {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};