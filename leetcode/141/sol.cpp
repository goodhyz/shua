/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if(head==NULL || head->next == NULL)return false;
            ListNode *slow=head,*fast=head;
            while(true){
            slow = slow->next;
            if(fast==NULL || fast->next ==NULL){
                return false;
            }
            fast = fast->next;
            fast = fast->next;
            if(fast==slow)return true;
            }
            return true;
        }
    };