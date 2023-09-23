// Time Complexity = O(n)
// Space Complexity = O(right - left + 1)

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        int count1 = 0;
        vector<int> arr;
        while(curr != nullptr){
            count1++;
            if(count1 >= left && count1 <= right){
                arr.push_back(curr->val);
            }
            curr = curr->next;
        }

        ListNode* curr2 = head;
        int count2 = 0;
        int idx = 0;
        while(curr2 != nullptr){
            count2++;
            if(count2 >= left && count2 <= right){
                curr2->val = arr[arr.size() - 1 - idx];
                idx++;
            }
            curr2 = curr2->next;
        }

        return head;
    }
};