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
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* head = new ListNode();
        ListNode* temp = head;
        int q = 0;
        int r = 0;
        int csum = 0;
        while(l1!= nullptr && l2!=nullptr){
            csum = l1->val + l2->val;
            q = (csum+r)%10;
            r = csum/10;
            ListNode* newNode = new ListNode(q);
            temp->next = newNode;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=nullptr){
            csum = l1->val + r;
            q = (csum)%10;
            r = csum/10;
            ListNode* newNode = new ListNode(q);
            temp->next = newNode;
            temp = temp->next;
            l1=l1->next;
        }
        while(l2!=nullptr){
            csum = l2->val + r;
            q = (csum)%10;
            r = csum/10;
            ListNode* newNode = new ListNode(q);
            temp->next = newNode;
            temp = temp->next;
            l2=l2->next;
        }
        if(r!=0){
            ListNode* newNode = new ListNode(r);
            temp->next = newNode;
        }
        return head->next;
    }
};
