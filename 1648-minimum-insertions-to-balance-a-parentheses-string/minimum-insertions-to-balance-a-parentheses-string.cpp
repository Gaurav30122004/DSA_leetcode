class Solution {
public:
    int minInsertions(string s) {
        
        stack<char> sto;
        stack<char> stc;
        int k =0;

        for(int i=0; i< s.size(); i++)
        {
            if(sto.empty() && stc.empty())
            {
                if(s[i] == ')'){
                    sto.push('(');      // changed: inserted '('
                    stc.push(s[i]);
                    k++;                // changed
                    continue;
                }
                else{
                    sto.push(s[i]);
                    continue;
                }
            }
            else if(s[i] == ')' && !sto.empty() && !stc.empty())
            {
                stc.pop();
                sto.pop();
                continue;
            }
            else if(s[i] == ')')
            {
                // here stc is empty and sto is non-empty
                stc.push(s[i]);
                continue;
            }
            else if(s[i] == '(')
            {
                if(!stc.empty())        // changed: pending single ')' needs a partner
                {
                    k++;
                    stc.pop();
                    sto.pop();
                }
                sto.push(s[i]);
                continue;
            }
        }
        return 2*(int)sto.size() - (int)stc.size() + k;   // changed: casts, cout removed
    }
};