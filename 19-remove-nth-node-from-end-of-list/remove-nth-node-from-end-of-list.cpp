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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* curr= head;
        int size = 0;
        while(curr!= NULL)
        {
            size++;
            curr= curr->next;
        }
        int k = size-n +1;
        ListNode* back =nullptr;
        curr = head;

        if(k==1)
        {
            back = head;
            head = head->next;
            delete back;
            return head;
        } 

        int cnt=0;
        while(curr!= NULL)
        {
            cnt++;
            if(cnt == k)
            {
                back->next = curr->next;
                delete curr;
                break;
            }
            back = curr;
            curr= curr->next;
        }
        return head;
    }
};