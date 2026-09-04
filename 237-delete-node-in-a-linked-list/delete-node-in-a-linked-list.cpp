/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {

        // tried to swap node val to its front and then when node val comes at last del that node 
        // ListNode* prev = node;
        // ListNode* front = prev->next;
        // ListNode* beforeprev = nullptr;

        // while(front != NULL)
        // {
        //     int temp= prev->val;
        //     prev->val = front->val;
        //     front->val = temp;

        //     beforeprev = prev;
        //     prev= front;
        //     front= front->next;
        // }
        // beforeprev->next = nullptr;
        // delete prev;
        
        ListNode* prev = nullptr;
        while(node->next != nullptr)
        {
        node->val = node->next->val;
        prev = node;
        node= node->next;
        }
        prev->next = nullptr;
        delete node;

    }
};