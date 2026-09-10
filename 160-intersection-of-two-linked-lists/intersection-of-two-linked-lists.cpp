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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        map<ListNode* ,int> mapNode ;

        while(tempA != NULL)
        {
                mapNode[tempA] = 1;
                tempA = tempA->next;
        }
        while(tempB != NULL)
        {
            auto it = mapNode.find(tempB);
            if(it != mapNode.end())
            {
                return tempB;
            }
            tempB = tempB->next;
        }
        return NULL;
    }
};