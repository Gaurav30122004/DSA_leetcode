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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        int cnt =0; 
        ListNode* back = nullptr;
        while(fast != NULL && fast->next != NULL)
        {
            back = slow; 
            slow = slow->next;
            fast = fast->next->next;       // for odd len ll ,jab 
        }
        back->next = slow->next;
        slow->next = nullptr;
        delete slow;
        return head;
    }
};