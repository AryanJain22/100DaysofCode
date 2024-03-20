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
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* dummy=list1;
        ListNode* last=list2;
        int c=0;
        while(last->next!=NULL){
            last=last->next;
            c++;
        }
        b=b+1;
        while(b--){
            dummy=dummy->next;
        }
        a=a-1;
        while(a--){
            temp1=temp1->next;
        }
        temp1->next=temp2;
        last->next=dummy;

        return list1;

    }
};
