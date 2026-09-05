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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // find which is bada

        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int cnt1=0 , cnt2=0;
        while(t1 != NULL || t2 != NULL)
        {
            if(t1 != NULL)
            {
                cnt1++;
                t1= t1->next;
            }
            if(t2 != NULL){
                 cnt2++;
                 t2= t2->next;
            }
        }

        ListNode* newHead = new ListNode();
        ListNode* result = newHead;
        int len = (cnt1>cnt2)? cnt1 : cnt2;
        for(int i=0; i<len-1; i++)
        {
            ListNode* newNode = new ListNode();
            result->next = newNode;
            result = result->next;
        }
        result= newHead;

        if(cnt1>= cnt2)
        {
            t1 = l1;
            t2 = l2;
        }
        else{
            t1= l2;
            t2= l1;
        }
        int carry=0;
        bool carryFlag;
        while(t1 != NULL || t2 != NULL)
        {
            int v1= (t1 != NULL)? t1->val:0;
            int v2= (t2 != NULL)? t2->val:0;
            int x = v1+v2 +carry;
            carryFlag=0;
            if(x<10){
                result->val = x;
                carryFlag =0;
                carry=0;
            }
            else{
                result->val = x%10;
                carry = x/10;
                carryFlag = 1;
                
                
            }
            if(result->next != nullptr){
            result = result->next;
            }

            t1= (t1!= NULL)? t1->next:  t1;
            t2= (t2!= NULL)? t2->next: t2;
        }
        if (carryFlag==1)
        {
            ListNode* lastNode = new ListNode(carry);
            result->next= lastNode;
        }
        return newHead;
    }
};