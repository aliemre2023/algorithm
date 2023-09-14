// Time Complexity = O(n)
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
    ListNode* middleNode(ListNode* head) {
        int length = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            curr = curr->next;
            length++;
        }

        int count = 0;
        while(count < length / 2){
            count++;
            head = head->next;
        }
        return head;
    }
};