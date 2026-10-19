class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        vector<int> ans;
        int idx =0;
        int cnt =0;
        for(int i=0; i<nums.size(); i++)
        {
            if (nums[i] == target)
            {
                cnt++;
            }
            if(nums[i] < target)
            {
                idx++;
            }
        }

        for(int i= idx; i<idx+cnt; i++)
        {
            ans.push_back(i);
        }










           // for(int i=0; i<nums.size(); i++)
        // {
        //     if(nums[i] == target)
        //     {
        //         ans.push_back(i);
        //     }
        // }
        return ans;
    }
};