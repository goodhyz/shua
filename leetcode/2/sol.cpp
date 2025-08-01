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
class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode();
        ListNode *current = head;
        int carry = 0;
        while (l1 != NULL || l2 != NULL) {
            int sum = 0;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;  // 计算进位
            sum = sum % 10;     // 计算当前节点值
            current->next = new ListNode(sum); // 创建新节点
            current = current->next;
        }
        if(carry>0){
            current->next = new ListNode(carry);
        }
        return head->next;
    }
};