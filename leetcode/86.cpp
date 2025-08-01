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

 /**
  * 写链表题时一定要注意，右值是否已经更改过，否则容易造成赋值错误，构成环等
  * 循环时记得写更新条件，更新指针，常常忘记
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
    ListNode *partition(ListNode *head, int x) {
        if (NULL == head || NULL == head->next)
            return head;
        ListNode *dummy = new ListNode(-101, head);
        ListNode *left = dummy;
        while (left->next && left->next->val < x) {
            left = left->next;
        }
        ListNode *pre_right = left;
        ListNode *right = left->next;
        if (!right)
            return head; // 没有大于等于x的节点
        while (right) {
            if (right->val < x) {
                ListNode *right_nex = right->next;

                // delete
                pre_right->next = pre_right->next->next;//先删除，写链表题时一定要注意，右值是否已经更改过
                // insert
                ListNode *nex = left->next;
                left->next = right;
                right->next = nex;

                // 下一步
                left = left->next; //又忘了
                right = right_nex;

            } else {
                right = right->next;
                pre_right = pre_right->next; // 记得更新条件
            }
        }
        return dummy->next;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(2);
    s.partition(head, 3);
    ListNode *h = head;
    while (h) {
        cout << h->val;
        h = h->next;
    }

    return 0;
}