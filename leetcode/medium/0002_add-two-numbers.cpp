// Time Complexity = O(m + n)
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_temp = l1;
        ListNode* l2_temp = l2;
        int digit_sum = 0;
        int surplus = 0;
        while(l1 != nullptr && l2 != nullptr){
            digit_sum = l1->val + l2->val;
            if(surplus == 1){
                surplus = 0;
                digit_sum += 1;
            }
            if(digit_sum >= 10){
                surplus = 1;
                digit_sum -= 10;
            }
            l1->val = digit_sum;
            l2->val = digit_sum;
            if(l1->next == nullptr && l2->next == nullptr){
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        bool l1_longer = true;
        while(l1 != nullptr && l2 == nullptr){
            l1_longer = true;
            if(surplus == 1){
                surplus = 0;
                l1->val += 1;
                if(l1->val >= 10){
                    l1->val -= 10;
                    surplus = 1;
                }
            }
            if(l1->next == nullptr) break;
            l1 = l1->next;
        }
        while(l2 != nullptr && l1 == nullptr){
            l1_longer = false;
            if(surplus == 1){
                surplus = 0;
                l2->val += 1;
                if(l2->val >= 10){
                    l2->val -= 10;
                    surplus = 1;
                }
            }
            if(l2->next == nullptr) break;
            l2 = l2->next;
        }
        
        if(surplus == 1){
            ListNode* new_node = new ListNode(1);
            if(l1_longer){
                l1->next = new_node;
            }
            else{
                l2->next = new_node;
            }
        }
        
        return l1_longer ? l1_temp : l2_temp;
    }
};