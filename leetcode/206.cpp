struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 迭代写法
class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }
};

// 递归写法
class Solution1 {
public:
  ListNode *reverseList(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *new_head = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
  }
};

int main() { 
    return 0; 
}