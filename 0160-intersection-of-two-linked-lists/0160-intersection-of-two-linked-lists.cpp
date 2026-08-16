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
        int n1 = 1, n2 = 1;
        ListNode *tmp = headA, *tmpa = headA, *tmpb = headB;
        while(tmp!=nullptr){
            tmp=tmp->next;
            n1++;
        }

        tmp = headB;
        while(tmp!=nullptr){
            tmp = tmp->next;
            n2++;
        }

        int diff =abs(n2 - n1);
        if(n2>n1){
            while(diff>0){
                tmpb = tmpb->next;
                diff--;
            }
        }
        else{
            while(diff>0){
                tmpa = tmpa->next;
                diff--;
            }
        }

        while(tmpa && tmpb){
            if(tmpa == tmpb) return tmpa;

            tmpa = tmpa->next;
            tmpb = tmpb->next;
        }
        return nullptr;
    }
};