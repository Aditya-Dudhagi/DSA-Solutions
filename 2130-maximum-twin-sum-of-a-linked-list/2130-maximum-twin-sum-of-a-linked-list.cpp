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
    int pairSum(ListNode* head) {
        ListNode* slow=head, *fast = head;
        stack<int> st;
        while(fast!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        while(slow){
            st.push(slow->val);
            slow = slow->next;
        }

        int ans = INT_MIN;
        slow  = head;
        while(!st.empty()){
            ans = max(ans, slow->val+st.top());
            slow = slow->next;
            st.pop();
        }
        return ans;
    }
};