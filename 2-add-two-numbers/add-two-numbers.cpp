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
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;
        while(l1 != NULL || l2!=NULL || carry!=0) {
            int v1; int v2;
            if(l1!=NULL) {
                v1 = l1->val;
            } else {
                v1 = 0;
            }
            if(l2!=NULL) {
                v2 = l2->val;
            } else {
                v2 = 0;
            }

            int val = v1+v2+carry;
            carry = val/10;
            val = val%10;
            temp->next = new ListNode(val);
            temp = temp->next;

            if(l1!=NULL) {
                l1 = l1->next;
            } else {
                l1 = NULL;
            }
             if(l2!=NULL) {
                l2 = l2->next;
            } else {
                l2 = NULL;
            }
        }

        ListNode* res = dummy->next;
        return res;
        


    }
};