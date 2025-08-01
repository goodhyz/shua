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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy;
        while(pre->next&&pre->next->next){
            if(pre->next->val == pre->next->next->val){
                while(pre->next->next->val==pre->next->next->next->val){
                    pre->next->next->next =pre->next->next->next->next;
                }
                pre->next = pre->next->next->next;
            }else{
                pre = pre->next;
            }
        }
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
    ListNode *h = head;
    while (h) {
        cout << h->val;
        h = h->next;
    }

    return 0;
}