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
        ListNode *slow = head, *fast = head, *before = head;
        if(head -> next == nullptr) return head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            before = slow;
            slow = slow->next; 
            fast = fast->next->next;
        }
        before->next = slow->next;
        delete slow;
        return head;
    }
};