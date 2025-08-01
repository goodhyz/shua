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
        ListNode* rotateRight(ListNode* head, int k) {
            // 判断没有元素和一个元素的时候
            if(NULL == head || NULL == head->next)return head;

            // 可以用一个count计算，没必要使用vector 浪费内存
            vector<ListNode*>ptrs;
            ListNode*h =head;
            while(h->next){
                ptrs.push_back(h);
                h = h->next;
            }
            ptrs.push_back(h);
            h->next =head;
            int len = ptrs.size();
            k=k%len;
            // 返回
            head = ptrs[(len-k)%len];
            ListNode* tail= ptrs[len-k-1];
            tail->next = NULL;
            return head;
        }

        ListNode* rotateRight(ListNode* head, int k) {
            // 判断没有元素和一个元素的时候
            if(NULL == head || NULL == head->next || 0==k)return head;

            ListNode* h=head;
            int len = 1;
            while(h->next){
                len++;
                h=h->next;
            }
            k=k%len;
            if(!k)return head;
            // 构成环
            h->next=head;
            int add = len-k-1;
            h =head;
            while(add--){
                h=h->next;
            }
            head = h->next;
            h->next = NULL;

            return head;
        }
    };
 
 int main() {
     Solution s;
     ListNode *head = new ListNode(1);
     head->next = new ListNode(2);
     s.rotateRight(head,0);
     ListNode *h = head;
     while (h) {
         cout << h->val;
         h = h->next;
     }
 
     return 0;
 }