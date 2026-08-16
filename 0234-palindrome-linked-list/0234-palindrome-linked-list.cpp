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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* tmp = head;
        while(tmp != NULL){
            st.push(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp!=NULL){
            if(tmp->val != st.top()){
                return false;
            }
            st.pop();
            tmp = tmp->next;
        }
        return true;
    }
};