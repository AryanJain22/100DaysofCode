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
    ListNode* reverse(ListNode* node){
        if(node == NULL){
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        ListNode* curr = node;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* node = reverse(head);
        ListNode* temp = node;
        ListNode* prev = NULL;
        int carry = 0;
        while(temp != NULL){
            int val = temp->val;
            int mul = val*2+carry;
            temp->val = mul%10;
            carry = mul/10;
            prev = temp;
            temp = temp->next;

        }
        if(carry == 1){
            ListNode* newnode = new ListNode(1);
            prev->next = newnode;
        }
        ListNode* ans = reverse(node);
        return ans;
    }
};