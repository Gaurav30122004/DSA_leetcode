class Solution {
    void subs(int idx, vector<int> &temp, vector<int> nums,vector<vector<int>> &ans)
    {
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        subs(idx+1,temp,nums,ans);

        temp.pop_back();
        subs(idx+1,temp,nums,ans);
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans ;
       vector<int> temp;

        subs(0,temp,nums,ans);

        return ans ;
    }
};