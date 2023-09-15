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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        ListNode* temp;
        int count = 0;

        while(count < a - 1){
            curr = curr->next;
            count++;
        }

        temp = curr->next;
        curr->next = list2;

        while(list2->next != nullptr){
            list2 = list2->next;
            count++;
        }
        for(int i = a; i <= b; i++){
            temp = temp->next;
        }

        list2->next = temp;

        return list1;
    }
};