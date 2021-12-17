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
        ListNode prehead(0, head);
        ListNode *l = &prehead;
        while((--n)) {
            head = head->next; 
        }
        while(head->next) {
            head = head->next;
            l = l->next;
        }
        l->next = l->next->next;
        return prehead.next;
    }
};