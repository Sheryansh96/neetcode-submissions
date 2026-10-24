/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node *nHead = new Node(head->val);
        unordered_map<Node*, int> truemp;
        unordered_map<int, Node*> copymp;
        Node* thead = head->next;
        Node* temp = nHead;
        truemp[head] = 0;
        copymp[0] = nHead;
        int pos = 1;
        while(thead!=nullptr){
            Node* n = new Node(thead->val);
            truemp[thead] = pos;
            temp->next = n;
            temp = temp->next;
            copymp[pos] = temp;
            thead = thead->next;
            pos++;
        }

        Node* realHead = head;
        Node* copyHead = nHead;
        while(realHead!=nullptr){
            if(realHead->random!=nullptr){
                int pos = truemp[realHead->random];
                copyHead->random = copymp[pos];
            }
            realHead = realHead->next;
            copyHead = copyHead->next;
        }
        return nHead;
    }
};
