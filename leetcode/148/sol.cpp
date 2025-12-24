#include <algorithm>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
// #include <

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
  ListNode *sortList(ListNode *head) {
    if (!head)
      return head;
    ListNode *node = head;
    while (node->next) {
      node = node->next;
    }
    return mergerSort(head, node);
  }

  // head 为闭，tail 为开，即可以为nullptr
  // ListNode* mergerSort(ListNode* head,ListNode* tail){
  //     // 停止条件
  //     if(head->next == tail){
  //         head ->next = nullptr;
  //         return head;
  //     }
  //     // 找中点, fast 最终为 tail
  //     ListNode *slow=head, *fast=head;
  //     while(fast!=tail){
  //         slow = slow->next;
  //         fast = fast->next;
  //         if(fast != tail){
  //             fast = fast->next;
  //         }
  //     }
  //     ListNode* mid = slow;

  //     ListNode* h1 = mergerSort(head, mid);
  //     ListNode* h2 = mergerSort(mid, tail);
  //     return merge(h1,h2);
  // }

  ListNode *merge(ListNode *h1, ListNode *h2) {
    ListNode *dummy = new ListNode(-10086);
    ListNode *head = dummy;
    while (h1 && h2) {
      if (h1->val <= h2->val) {
        dummy->next = h1;
        h1 = h1->next;
      } else {
        dummy->next = h2;
        h2 = h2->next;
      }
      dummy = dummy->next;
    }
    if (h1) {
      dummy->next = h1;
    }
    if (h2) {
      dummy->next = h2;
    }
    return head->next;
  }

  // head 和 tail 都为闭，注意 head == tail 以及 只有两个节点时的slow 和 fast 的运作，以及 mid->next
  ListNode *mergerSort(ListNode *head, ListNode *tail) { 
    // 停止条件
    if (head == tail) {
      head->next = nullptr;
      return head;
    }
    // 找中点, fast 最终为 tail
    ListNode *slow = head, *fast = head;
    while (fast != tail && fast->next != tail) {
      slow = slow->next;
      fast = fast->next;
      if (fast != tail) {
        fast = fast->next;
      }
    }
    ListNode *mid = slow;

    ListNode *h2 = mergerSort(mid->next, tail);
    ListNode *h1 = mergerSort(head, mid);
    return merge(h1, h2);
  }
};

int main() {
  string line;
  getline(cin, line);
  stringstream ss(line);
  int n;
  ListNode *dummy = new ListNode(-10086);
  ListNode *cur = dummy;
  while (ss >> n) {
    cur->next = new ListNode(n);
    cur = cur->next;
  }
  Solution sol;
  ListNode *newhead = sol.sortList(dummy->next);
  while (newhead) {
    cout << newhead->val << " ";
    newhead = newhead->next;
  }
}