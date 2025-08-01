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

 #include <iostream>
 using namespace std;
 
 class ListNode {
   public:
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

//  class Solution {
//     public:
//         ListNode* reverseKGroup(ListNode* head, int k) {
//             ListNode* dummy  = new ListNode();
//             dummy->next = head;
//             ListNode* begin = head;
//             ListNode * next_begin = NULL;
//             ListNode* pre = dummy;
//             ListNode* curr = head;
//             int count = 0;
//             while(curr){
//                 count++;
//                 if(k == count){
//                     pre->next = curr;
//                     pre = begin;
//                     next_begin = reverseLink(begin,curr);
//                     begin->next = next_begin;
//                     begin = curr = next_begin;
//                     count =0;
//                     continue;
//                 }
//                 curr = curr->next;
//             }
//             return dummy->next;
//         }

//         // 返回pair 表示新的头部和尾部 然后接进原来的链表 这样更清晰；
//         ListNode* reverseLink(ListNode*left,ListNode*right){
//             // 翻转链表 返回链表后的下一位
//             ListNode* behind=right->next;
//             ListNode *curr = left->next,*pre = left;
//             while(curr!=behind){
//                 ListNode*next = curr->next;
//                 curr->next = pre;
//                 pre = curr;
//                 curr = next;
//             }
//             return behind;
//         }
//     };  

class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* dummy  = new ListNode();
            dummy->next = head;
            ListNode* begin = head;
            ListNode * next_begin = NULL;
            ListNode* pre = dummy;
            ListNode* curr = head;
            int count = 0;
            while(curr){
                count++;
                if(k == count){
                    // 反转并接进来
                    next_begin = curr->next;
                    pair<ListNode*,ListNode*> pair = reverseLink(begin,curr);
                    pre->next = pair.first;
                    pair.second->next = next_begin;

                    // 更新 
                    pre = begin;
                    begin =curr =  next_begin;
                    count =0;
                    continue;
                }
                curr = curr->next;
            }
            return dummy->next;
        }

        // 返回pair 表示新的头部和尾部 然后接进原来的链表 这样更清晰；
        pair<ListNode*,ListNode*> reverseLink(ListNode*left,ListNode*right){
            // 翻转链表 返回新链表的头和尾部
            ListNode* behind=right->next;
            ListNode *curr = left->next,*pre = left;
            while(curr!=behind){
                ListNode*next = curr->next;
                curr->next = pre;
                pre = curr;
                curr = next;
            }
            return {right,left};
        }
    }; 

    int main() {
        Solution s;
        ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        ListNode* h = s.reverseKGroup(head, 2);
        
        while(h){
            cout<<h->val;
            h=h->next;
        }  
        
        return 0;
    }