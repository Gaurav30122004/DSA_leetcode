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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy ;
        ListNode* t1 = list1;
        ListNode* t2 = list2;

        while(t1 != NULL && t2 != NULL)
        {
            if(t1->val <= t2->val)
            {
                curr->next = t1;
                t1 = t1->next;
            }
            else{
                curr->next = t2;
                t2= t2->next;
            }
            curr = curr->next;
        }

        if(t1 == NULL)
        {
            curr->next = t2;
        }
        else {
            curr->next = t1;
        }
        return dummy->next;
        
    }
};