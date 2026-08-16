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
        if(!headA || !headB) return NULL;

        ListNode *tmpa = headA, *tmpb = headB;
        while(tmpa != tmpb){
            tmpa = tmpa->next;
            tmpb = tmpb->next;

            if(tmpa == tmpb) return tmpa;

            if(tmpa == NULL) tmpa = headB;
            if(tmpb == NULL) tmpb = headA;
        }
        return tmpa;
    }
};