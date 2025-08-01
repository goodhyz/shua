#include <bits/stdc++.h>

using namespace std;
class MaxHeap {
  public:
    vector<vector<int>> heap;
    int count;

  public:
    MaxHeap() {
        count = 0;
    }
    void modifyHeap(int root) {
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        int maxIdx = root;
        if (left < count && heap[maxIdx][0] + heap[maxIdx][1] < heap[left][0] + heap[left][1]) {
            maxIdx = left;
        }
        if (right < count && heap[maxIdx][0] + heap[maxIdx][1] < heap[right][0] + heap[right][1]) {
            maxIdx = right;
        }
        if (maxIdx != root) {
            swap(heap[root], heap[maxIdx]);
            modifyHeap(maxIdx);
        }
    }
    // push后如何调整堆
    void pushElement(vector<int> elem) {
        heap.push_back(elem);
        count++;
        int parent = (count - 2) / 2;
        for (;;) {
            modifyHeap(parent);
            if (!parent)
                break;
            parent = (parent - 1) / 2;
        }
    }
};

class Solution {
  private:
    MaxHeap maxHeap;

  public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        for (auto num1 : nums1) {
            if(maxHeap.count ==k && num1+nums2[0] >maxHeap.heap[0][0] + maxHeap.heap[0][1]){
                break;
            }
            for (auto num2 : nums2) {
                vector<int> elem = {num1, num2};
                int elemSum = num1 + num2;
                if (maxHeap.count < k) {
                    maxHeap.pushElement(elem);
                } else if (maxHeap.heap[0][0] + maxHeap.heap[0][1] > elemSum) {
                    // 找到更小的
                    maxHeap.heap[0][0] = num1;
                    maxHeap.heap[0][1] = num2;
                    maxHeap.modifyHeap(0);
                }else{
                    break;
                }
            }
            
        }
        vector<vector<int>> res;
        for (auto &elem : maxHeap.heap) {
            res.push_back(elem);
        }
        //sort(res.begin(),res.end());
        return res;
    }
};