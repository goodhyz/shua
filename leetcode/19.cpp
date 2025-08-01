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
 #include <vector>
 using namespace std;
 
 class ListNode {
   public:
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            vector<ListNode*> ptrs;
            ListNode* dummy = new ListNode(0,head);
            ptrs.push_back(dummy);
            while(head){
                ptrs.push_back(head);
                head = head->next;
            }
            ListNode*pre = ptrs[ptrs.size()-n-1];
            pre->next = pre->next->next; // 删除操作
            return dummy->next;
        }
    };

    int main() {
        Solution s;
        ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        
        while(h){
            cout<<h->val;
            h=h->next;
        }  
        
        return 0;
    }