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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next){
            return head;
        }
        ListNode* dummy = new ListNode(-101,head);
        ListNode* leftPre = dummy;
        // 找到第一个大于x的节点的前驱节点
        while(leftPre->next && leftPre->next->val <x){
            leftPre = leftPre->next;
        }
        // 为空直接return
        if(!leftPre){ return head; }
        ListNode* rightPre = leftPre;
        // 遍历所有
       while(rightPre->next){
            // 找到一个小于x的节点
            if(rightPre->next->val < x){
                ListNode* tmp = rightPre->next;
                rightPre ->next = rightPre->next->next;

                tmp->next = leftPre->next;
                leftPre->next = tmp;
                leftPre = leftPre ->next;
            } else {
                rightPre = rightPre->next;
            }
        }
        return dummy->next;
    }
};

int main() {
    _Solution s;
    vector<int> node_list = {1,4,3,0,2,5,2};
    ListNode* dummy = new ListNode(-191),* cur = dummy;
    for(int i =0;i<node_list.size();i++){
        cur->next = new ListNode(node_list[i]);
        cur = cur->next;
    }
    ListNode *h = s.partition(dummy->next, 3);
    while (h) {
        cout << h->val;
        h = h->next;
    }

    return 0;
}