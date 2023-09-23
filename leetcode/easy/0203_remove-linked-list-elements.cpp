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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(curr != nullptr){
            if(val == curr->val){
                ListNode* temp = curr->next;
                if(prev != nullptr){
                    prev->next = temp;
                } 
                else{
                    head = temp;
                }
                curr = temp;
            } 
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};