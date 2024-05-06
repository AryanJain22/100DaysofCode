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
    int lar = INT_MIN;
    ListNode* nextnode = nullptr;
    void removerecursively(ListNode* node) {
        if(node == nullptr) {
            return;
        }
        if(node -> next == nullptr) {
            lar = max(lar, node->val);
            nextnode = node;
            return;
        }
        removerecursively(node -> next);
        if(node -> val >= lar) {
            lar = node -> val;
            node -> next = nextnode;
            nextnode = node;
        }
        return;
    }

    ListNode* removeNodes(ListNode* head) {
        removerecursively(head);
        return nextnode;
    }
};