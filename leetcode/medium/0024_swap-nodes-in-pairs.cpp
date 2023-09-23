// Time Comlexity = O(n)
// Space Complexity = O(1) 

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;

        while(curr != nullptr && curr->next != nullptr){
            int temp1 = curr->val;
            curr->val = curr->next->val;
            curr = curr->next;
            curr->val = temp1;

            curr = curr->next;

        }
        return head;
    }
};