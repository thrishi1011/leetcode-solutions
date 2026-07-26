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

    int MiddleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        int pos = 0;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            pos++;
        }

        return pos;
    }

    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;

        ListNode* temp = head;
        int mid = MiddleNode(head);

        for(int i = 1; i < mid; i++) temp = temp->next;

        temp->next = temp->next->next;

        return head;
    }
};
