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
class Solution {
  public:
   /**
   又又一次没看清题，说的是交换left和right之间的节点，而不是交换left和right节点
   */
    ListNode *swapNodes(ListNode *head, int left, int right) {
        if (left == right)
            return head;
        ListNode *pre_head = new ListNode();
        pre_head->next = head;
        ListNode *pre_left, *pre_right;
        int count = 0;
        for (ListNode *h = pre_head; h; h = h->next, count++) {
            if (count == left - 1) {
                pre_left = h;
            }
            if (count == right - 1) {
                pre_right = h;
                break;
            }
        }
        swap(pre_left->next, pre_right->next);
        swap(pre_left->next->next, pre_right->next->next);
        return pre_head->next;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (left == right)
            return head;
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *pre_left, *pre_right,*right_node,*left_node,*suc_node;
        int count = 0;
        // 第一次遍历
        for (ListNode *h = dummy; h; h = h->next, count++) {
            if (count == left - 1) {
                pre_left = h;
            }
            if (count == right - 1) {
                pre_right = h;
                break;
            }
        }
        // 翻转 这里是重点 需要巩固一下，其实就是灵活用指针，在更新next前保存原本的next
        left_node = pre_left->next;
        right_node = pre_right->next;
        suc_node = right_node->next;
        ListNode *curr = pre_left->next->next;
        ListNode *pre =pre_left->next;
        while(curr!=suc_node){
            ListNode *next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        left_node->next = suc_node;
        pre_left->next = right_node;
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
    ListNode* h = s.reverseBetween(head, 2, 5);
    
    while(h){
        cout<<h->val;
        h=h->next;
    }
    
    return 0;
}