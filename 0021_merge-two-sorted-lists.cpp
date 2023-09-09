// Time Complexity = O(list1.size() + list2.size())
// Space Complexity = O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        // Arranging the head with the least element
        ListNode* head;
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        // Initalizing the list with head
        ListNode* sorted = head;
        // Sorting the in the sorted list
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                sorted->next = list1;
                list1 = list1->next;
            } else {
                sorted->next = list2;
                list2 = list2->next;
            }
            sorted = sorted->next;
        }

        // After the while loop, one of the lists might still have remaining nodes
        if (list1 != nullptr) {
            sorted->next = list1;
        } else {
            sorted->next = list2;
        }

        return head;
    }
};