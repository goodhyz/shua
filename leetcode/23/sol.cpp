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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKListsHelp(lists, 0, lists.size() - 1);
    }

    // 需要理解的是这个函数返回的是ListNode* 所以最后一个return 是merge2Lists(left,right)
    ListNode *mergeKListsHelp(vector<ListNode *> &lists, int s, int e) {
        if (s == e)
            return lists[s];
        // if(s+1==e)return merge2Lists(lists[s],lists[e]);
        if (s > e)
            return nullptr;
        int mid = (s + e) / 2;
        ListNode *left = mergeKListsHelp(lists, s, mid);
        ListNode *right = mergeKListsHelp(lists, mid + 1, e);
        return merge2Lists(left, right);
    }

    // 合并链表 重点
    ListNode *merge2Lists(ListNode *h1, ListNode *h2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *pre = dummy;
        if (h1 == nullptr)
            return h2;
        if (h2 == nullptr)
            return h1;
        while (h1 && h2) {
            if (h1->val > h2->val) {
                pre->next = h2;
                h2=h2->next;
            } else {
                pre->next = h1;
                h1=h1->next;
            }
            pre =pre->next;
        }
        pre->next = h1?h1:h2;
        ListNode *result = dummy->next;
        delete dummy;
        return result;
    }
};

int main() {
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(6);
    // l2->next->next = new ListNode(4);

    Solution s;
    ListNode *cur = s.merge2Lists(l1, l2);
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
}