class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int> even;
        vector<int> odd;

        sort(nums1.begin(), nums1.end());

        int n= nums1.size();

        for(int i=0; i< n; i++)
        {
            if(nums1[i]%2 == 0)
            {
                even.push_back(nums1[i]);
            }
            else
            {
                odd.push_back(nums1[i]);
            }
        }
        bool flag_odd= true;
        for(int i=0; i< odd.size(); i++)
        {
            for(int j=0; j< even.size(); j++)
            {
                if(odd.size() == n)
                {
                    flag_odd = false;
                    break;
                }
                
                    int diff = odd[i]-even[j];
                    odd.push_back(diff);
                
            }
            if(flag_odd == false)
            {
                break;
            }
        }

        bool flag_even = true;
        for(int i=0; i<even.size(); i++)
        {
            for(int j=i+1; j<even.size(); j++)
            {
                if(even.size() ==n)
                {
                    flag_even= false;
                    break;
                }
                int diff = even[i]-even[j];
                even.push_back(diff);
            }
            if(flag_even == false)
            {
                break;
            }
        }

        if(even.size()== n || odd.size() == n)
        {
            return true;
        }
        return false;
    }
};