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
        int sz = 0;
        ListNode* temp = head;
        while(temp!=nullptr){
            sz++;
            temp = temp->next;
        }
        ListNode* temp1 = head;
        ListNode* prev = temp1;
        int loop = sz-n;
        while(loop--){
            prev = temp1;
            temp1 = temp1->next;
        }
        if(temp1 == head){
            return head -> next;
        }
        prev->next = temp1->next;
        temp1->next = nullptr;
        return head;
    }
};
