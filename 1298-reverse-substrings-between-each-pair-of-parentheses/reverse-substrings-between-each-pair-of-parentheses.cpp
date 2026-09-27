class Solution {

public:
    string reverseParentheses(string s) {
      stack<char> st;
      int i=0;
      while( i< s.size())
      {
        char ch= s[i];
        if (ch != ')')
        {
            st.push(ch);
        }
        else{
            string str = "";
            while(st.top() != '(')
            {
                str.push_back(st.top());
                st.pop();
            }
            st.pop();
            for(char c : str)
            {
                st.push(c);
            }
        }
        i++;
      }
    string ans;
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    } 
    reverse(ans.begin(), ans.end());
    return ans ;     
    }
};