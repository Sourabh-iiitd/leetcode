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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = head->next->next;

        int first_crit = -1, prev_crit = -1;
        int ans = INT_MAX;
        int index = 1;

        while (next) {
           
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                
                if (first_crit == -1) {
                    first_crit = index;
                }
                if (prev_crit != -1) {
                    ans = min(ans, index - prev_crit);
                }
                prev_crit = index;
            }

            prev = curr;
            curr = next;
            next = next->next;
            index++;
        }

        if (ans == INT_MAX) {
            return {-1, -1};
        }

        return {ans, prev_crit - first_crit};
    }
};