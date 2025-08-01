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
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            if(left == right)return head;
            ListNode *dummy = new ListNode(0,head);
            ListNode* preNode = dummy;
            for(int i=0;i<left-1;i++){
                preNode = preNode->next;
            }
            ListNode* rightNode = preNode;
            for(int i=0;i<right-left+1;i++){
                rightNode = rightNode->next;
            }
            ListNode* nextNode = rightNode->next;
            ListNode* leftNode = preNode ->next;
    
            rightNode->next =nullptr;
    
            reverseLink(leftNode);
    
            leftNode->next = nextNode;
            preNode->next = rightNode;
            // 返回的是dummy->next
            return dummy->next;
    
        }
        ListNode* reverseLink(ListNode* head){
            ListNode* pre =nullptr;
            ListNode*cur =head;
            while(cur){
                ListNode* next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            return pre;
        }
    };