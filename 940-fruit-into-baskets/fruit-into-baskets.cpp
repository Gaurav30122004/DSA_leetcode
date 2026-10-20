class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int l=0, r=0;
        int maxLen = 0;

        while(r < fruits.size())
        {
            while(mp.size() >= 2 && mp.find(fruits[r]) == mp.end()) 
            {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0)
                {
                    mp.erase(fruits[l]);
                }
                l++;
            }

            mp[fruits[r]]++;

            maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};