// Time Complexity = O(n)
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int len = 0;
        while(curr != nullptr){
            curr = curr->next;
            len++;
        }
        if(len == n) return head->next;

        ListNode* curr2 = head;
        int curr_len = 0;
        while(curr_len != len-n-1 && curr2 != nullptr){
            curr_len++;
            curr2 = curr2->next;
        }

        if(curr2 == nullptr) return curr2->next;
        else if(curr2->next == nullptr) curr2 = nullptr;
        else if(curr2->next->next == nullptr) curr2->next = nullptr;
        else curr2->next = curr2->next->next;
        
        return head;
    }
};