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
private:
    struct NODE{
        int val;
        ListNode* ptr;
        NODE(int val, ListNode* ptr) : val(val), ptr(ptr) {

        }
        bool operator < (const NODE& rhs) const{
            return val > rhs.val;
        }
    };
    priority_queue<NODE> q;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head;
        ListNode *now = &head;
        for(auto i : lists) {
            if(i) q.push({i->val, i});
        }
        
        while(!q.empty()) {
            NODE top = q.top(); q.pop();
            now->next = top.ptr;   //ListNode *
            now = now->next;  //
            if(now->next) {
                q.push({(now->next)->val, now->next});
            }
        }

        return head.next;
    }
};

class Solution {
public:
    struct comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    priority_queue<ListNode*, vector<ListNode*>, comp> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push(node);
        }
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while (!q.empty()) {
            ListNode* node = q.top();
            q.pop();
            tail->next = node; 
            tail = tail->next;
            if (node->next) q.push(node->next);
        }
        return head->next;
    }
};