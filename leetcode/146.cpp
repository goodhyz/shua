#include <bits/stdc++.h>
using namespace std;

// class Node {
//   public:
//     int key;
//     int val;
//     Node *next;
//     Node(int k, int v) {
//         this->key = k;
//         this->val = v;
//         this->next = NULL;
//     }
// };

// /**
//  * 第一次写，用的单向链表，复杂度O(n) 太复杂
//  * 改进使用双向链表，降低复杂度到O(1)
//  */
// class LRUCache {
//   private:
//     // deque <pair<key,value>> cac
//     // int count;
//     // int members;
//     int capacity;
//     Node *dummy;
//     Node *tail;

//   public:
//     LRUCache(int capacity) {
//         this->capacity = capacity;
//         // this->members = 0;
//         this->dummy = new Node(0, 0);
//         this->tail = dummy;
//     }

//     int get(int key) {
//         Node *pre = this->dummy;
//         while (pre->next && pre->next->key != key) {
//             pre = pre->next;
//         }

//         // 把目标移到末尾
//         if (pre->next) {
//             this->tail->next = pre->next;
//             pre->next = pre->next->next;
//             this->tail = this->tail->next;
//             this->tail->next = NULL;
//             return this->tail->val;
//         } else {
//             return -1;
//         }
//     }

//     void put(int key, int value) {
//         Node *pre = this->dummy;
//         while (pre->next && pre->next->key != key) { // 把key写成val了
//             pre = pre->next;
//         }
//         if (pre->next) {
//             this->tail->next = pre->next;
//             pre->next = pre->next->next;
//             this->tail = this->tail->next;
//             this->tail->next = NULL;
//             this->tail->val = value;
//         } else if (capacity) {
//             this->tail->next = new Node(key, value);
//             this->tail = this->tail->next;
//             this->capacity--;
//         } else {
//             // 先加后删
//             this->tail->next = new Node(key, value); // next忘写了
//             this->tail = this->tail->next;
//             Node *del = this->dummy->next;
//             this->dummy->next = this->dummy->next->next;
//             delete del;
//         }
//     }
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//使用双向链表
class Node {
  public:
    Node(int k, int v, Node *p1 = nullptr, Node *p2 = nullptr) :key(k),val(v),pre(p1),next(p2){
    }

    int key;
    int val;
    Node *pre;
    Node *next;
};

class LRUCache{
    private:
    Node*dmHead;
    Node*dmTail;
    int capacity;
    unordered_map<int,Node*> map;
    
    public:
    LRUCache(int c){
        capacity = c;
        dmHead = new Node(-1,-1);
        dmTail = new Node(-1,-1);
        dmHead ->next = dmTail;
        dmTail ->pre = dmHead;
    }

    int get(int k){
        if(map.count(k)){//找到
            Node* target = map[k];
            target->pre->next = target->next;
            target->next->pre = target->pre;

            dmHead->next->pre = target;
            target->next = dmHead->next;
            target->pre = dmHead;
            dmHead->next = target;
            return target->val;

        }
        return -1;
    }

    void put(int k,int v){
        // 没找到
        if(!map.count(k)){
            if(capacity == 0){
                Node* new_node = new Node(k,v);
                // 插入
                new_node ->next = dmHead->next;
                new_node->pre = dmHead;
                dmHead->next->pre = new_node;
                dmHead->next = new_node;
                map[k]=new_node;
                // 删除
                Node* toDelete = dmTail->pre;
                toDelete->pre->next = dmTail;
                dmTail->pre = toDelete ->pre;
                map.erase(toDelete->key);
                delete toDelete;
            }else{
                Node* new_node = new Node(k,v);
                // 插入
                new_node ->next = dmHead->next;
                new_node->pre = dmHead;
                dmHead->next->pre = new_node;
                dmHead->next = new_node;
                capacity--;
                map[k]=new_node;
            }
        }else{
            Node* target = map[k];
            target->pre->next = target->next;
            target->next->pre = target->pre;

            dmHead->next->pre = target;
            target->next = dmHead->next;
            target->pre = dmHead;
            dmHead->next = target;
            target->val = v;
        }
    }
};
int main(){
    
    
}