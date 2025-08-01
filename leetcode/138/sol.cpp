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
            unordered_map <Node*,Node*> m;//原链表与新链表的对应
            Node* new_head = new Node(-1);
            Node* curr=new_head;
            Node* copyhead = head;
            while(head){
                curr->next = new Node(head->val);
                curr = curr->next;
                m[head]=curr;
                head = head->next;
            }
            head = copyhead;
            curr = new_head->next;
            while(head){
                curr->random = m[head->random];
                curr = curr->next;
                head = head->next;
            }
            return new_head->next;
        }
    };