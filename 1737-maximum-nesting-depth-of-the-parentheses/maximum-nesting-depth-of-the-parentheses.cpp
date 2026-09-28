class Solution {
public:
    int maxDepth(string s) {
        int max = INT_MIN;
        int cnt =0;

        for(int i=0; i<s.size(); i++)
        {
            char ch = s[i];
            if(ch == '(')  cnt++;
            else if (ch == ')') cnt--;

            max = (cnt>max)? cnt : max;
        }

        return max;
    }
};