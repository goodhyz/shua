#include <iostream>
#include <vector>

using namespace std;

class Solution {
  private:
    vector<int> heap;

  public:
    // 找第k大的数字，用小顶堆（k）
    int findKthLargest(vector<int> &nums, int k) {
        heap.resize(k);
        for (int i = 0; i < k; i++) {
            heap[i] = nums[i];
        }
        // 2*n+1 == k-1 or 2*n+2 == k-1
        for (int i = (k - 2) / 2; i >= 0; i--) {
            modifyHeap(heap, i);
        }
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > heap[0]) {
                heap[0] = nums[i];
                modifyHeap(heap, 0);
            }
        }
        return heap[0];
    }

    void modifyHeap(vector<int> &heap, int root) {
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        int n = heap.size();
        int max = root;
        if (left < n && heap[left] < heap[max]) {
            max = left;
        }
        if (right < n && heap[right] < heap[max]) {
            max = right;
        }
        if (root != max) {
            swap(heap[root], heap[max]);
            modifyHeap(heap, max);
        }
    }
};