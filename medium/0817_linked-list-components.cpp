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
    int numComponents(ListNode* head, vector<int>& nums) {
        ListNode* curr = head;

        while(curr != nullptr){
            for(int i = 0; i < nums.size(); i++){
                if(curr->val == nums[i]){
                    curr->val = -1;
                    break;
                }
            }
            curr = curr->next;
        }

        int component = 0;
        while(head != nullptr){
            if(head->val == -1){
                component++;
                while(head != nullptr && head->val == -1){
                    head = head->next;
                }
            } 
            else{
                head = head->next;
            }
        }
        return component;
    }
};