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
        ListNode *node1 = l1, *node2 = l2, *head = NULL;
        ListNode *pre = NULL, *now = NULL;
        int overflow = 0, sum, newVal;
        while(1) {
            if((node1 || node2) == NULL && !overflow) break;
            sum = getVal(node1) + getVal(node2) + overflow;
            newVal =  sum % 10;
            overflow =  sum / 10;
            if(head == NULL) {
                head = new ListNode(newVal);
                pre = head;
            }else{
                // sum = getVal(node1) + getVal(node2) + overflow;
                // newVal =  sum % 10;
                // overflow =  sum / 10;
                now = new ListNode(newVal);
                pre->next = now;
                pre = now;
            }
            node1 = getNext(node1);
            node2 = getNext(node2);
        }
        return head;
    }

    ListNode* getNext(ListNode* ptr) {
        if(!ptr) return NULL;
        return ptr->next;
    }

    int getVal(ListNode* ptr) {
        if(!ptr) return 0;
        return ptr->val;
    }
};