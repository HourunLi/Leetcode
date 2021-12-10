#include<bits/stdc++.h>
using namespace std;
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
    bool bigger(int a, int b) {
        return a > b;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ret, *now;
        ListNode *p1 = list1, *p2 = list2;
        if(!list1) {
            return list2;
        }else if(!list2) {
            return list1;
        }
        if(bigger(list1->val, list2->val)) {
            ret = list2;
            p2 = p2->next;
        }else{
            ret = list1;
            p1 = p1->next;
        }
        now = ret;
        while(p1 || p2) {
            if(!p1) {
                now->next = p2;
                return ret;
            }else if(!p2){
                now->next = p1;
                return ret;     
            }
            if(bigger(p1->val, p2->val)) {
                now->next = p2;
                p2 = p2->next;
            }else{
                now->next = p1;
                p1 = p1->next;    
            }
            now = now->next;
        }
        return ret;
    }
};
