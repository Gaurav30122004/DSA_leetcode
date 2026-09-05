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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == nullptr || head->next->next == nullptr)
        {
            return head;
        }

        ListNode* t1 = head;
        ListNode* t2 = t1->next;
        ListNode* evenHead = t2;
        ListNode* oddHead= nullptr;

        while(t1 != NULL && t2 != NULL)
        {
            t1->next = t2->next;
            oddHead = t1;
            t1= t2->next;

            if(t1){
            t2->next= t1->next;
            t2= t1->next;
            }
        }
        if(t1) t1->next = evenHead;
        else oddHead->next = evenHead;

        return head;

    }
};