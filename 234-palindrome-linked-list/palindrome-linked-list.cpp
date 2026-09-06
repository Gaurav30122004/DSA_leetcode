/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        vector<int> nums;
        while(curr != NULL)
        {
            nums.push_back(curr->val);
            curr= curr->next;
        }
        int n= nums.size() -1;
        for(int i=0; i<=n; i++)
        {
            cout<<nums[i]<<" ";
        }
        cout<<endl;
       
        curr = head;
        while(curr != NULL)
        {
            cout<<"chcing"<<curr->val<<" "<<nums[n]<<endl;
            if(curr->val != nums[n])
            {
                return false;
            }
            curr= curr->next;
            n--;
        }
        return true;
    }
};