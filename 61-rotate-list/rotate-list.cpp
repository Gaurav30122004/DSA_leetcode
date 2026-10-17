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
    ListNode* rotateRight(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            size++;
            temp = temp->next;
        }

        if(head == NULL || head->next == NULL || k%size == 0)
        {
            return head;
        }

        ListNode* curr = head;
        ListNode* front = curr->next;
        int n = k%size ;
        int cnt=1;

        while(cnt < size -n)
        {
            curr = curr->next;
            front = curr->next;
            cnt++;
        }
        curr->next = NULL;
        temp = front ;
        while(temp ->next != NULL)
        {
             temp = temp->next;
        }

        temp ->next = head;
        return front;
    }
};