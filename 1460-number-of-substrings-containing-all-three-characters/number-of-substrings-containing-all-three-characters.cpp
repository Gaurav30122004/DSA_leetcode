class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int cnt=0;
        int n= s.size();
        vector<int> lastseen = {-1,-1,-1};

        for (int i=0; i<n; i++)
        {
            lastseen[s[i] - 'a'] =i;
            
            if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1)
            {
                int MIN = min(lastseen[0],lastseen[1]);
                 MIN = min(MIN,lastseen[2]);             // min({ lastseen[0],lastseen[1],lastseen[2]}) // initializer list 
                cnt = cnt + (1+ MIN);
            }

        }
        return cnt;
    }
};