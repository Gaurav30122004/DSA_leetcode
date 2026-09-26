class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string,string> mp ;
        for (int i=0; i< knowledge.size(); i++)
        {
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        string ans ="";
        int len = s.size();
        int idx =0;
        while(idx < len)
        {
            if (s[idx] == '(')
            {
                idx++;
                string temp = "";
                while(s[idx] != ')')
                {
                    
                    temp += s[idx];
                    idx++;
                }
                idx++;
                auto it = mp.find(temp);
                ans += (it != mp.end())? mp[temp] : "?" ;

            }
            else{
            ans = ans + s[idx]; 
            idx++;
            }
        }
        return ans ;
        
    }
};