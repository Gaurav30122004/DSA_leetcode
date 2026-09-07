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
    int getDecimalValue(ListNode* head) {
        ListNode* curr= head;
        int size=0;
        while(curr!= NULL)
        {
            size++;
            curr= curr->next;
        }
        curr= head;
        int n = size-1;
        int sum= 0;
        while(curr!= NULL)
        {
            int val = (curr->val)* (int) pow(2,n) ;
            sum = sum + val;
            n--;
            curr= curr->next;
        }
        return sum;

    }
};