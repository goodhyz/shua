#include <bits/stdc++.h>

using namespace std;
// 两个问题
// 堆新增元素后如何调整堆
// 新增元素应该插入哪个堆
class MaxHeap {
  public:
    vector<int> heap;
    int count;

  public:
    MaxHeap() {
        count = 0;
    }
    void modifyHeap(int root) {
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        int maxIdx = root;
        if (left < count && heap[maxIdx] < heap[left]) {
            maxIdx = left;
        }
        if (right < count && heap[maxIdx] < heap[right]) {
            maxIdx = right;
        }
        if (maxIdx != root) {
            swap(heap[root], heap[maxIdx]);
            modifyHeap(maxIdx);
        }
    }
    // push后如何调整堆
    void pushElement(int num) {
        heap.push_back(num);
        count++;
        int parent = (count - 2) / 2;
        for (;;) {
            modifyHeap(parent);
            if (!parent)
                break;
            parent = (parent - 1) / 2;
        }
    }
    int getTop() {
        return heap[0];
    }
};

class MinHeap {
  public:
    vector<int> heap;
    int count;

  public:
    MinHeap() {
        count = 0;
    }
    void modifyHeap(int root) {
        int left = 2 * root + 1;
        int right = 2 * root + 2;
        int minIdx = root;
        if (left < count && heap[minIdx] > heap[left]) {
            minIdx = left;
        }
        if (right < count && heap[minIdx] > heap[right]) {
            minIdx = right;
        }
        if (minIdx != root) {
            swap(heap[root], heap[minIdx]);
            modifyHeap(minIdx);
        }
    }
    void pushElement(int num) {
        heap.push_back(num);
        count++;
        int parent = (count - 2) / 2;
        for (;;) {
            modifyHeap(parent);
            if (!parent)
                break;
            parent = (parent - 1) / 2;
        }
    }
    int getTop() {
        return heap[0];
    }
};

class MedianFinder {
  private:
    MaxHeap maxHeap;
    MinHeap minHeap;
    int count;

  public:
    MedianFinder() {
        count = 0;
    }

    // push到哪个堆呢
    void addNum(int num) {
        if (count == 0) {
            maxHeap.pushElement(num);
        } else if (count % 2 == 1) {
            if (num < maxHeap.getTop()) {
                swap(maxHeap.heap[0], num);
                maxHeap.modifyHeap(0);
            }
            minHeap.pushElement(num);
        } else {
            if (num > minHeap.getTop()) {
                swap(minHeap.heap[0], num);
                minHeap.modifyHeap(0);
            }
            maxHeap.pushElement(num);
        }
        count++;
    }

    double findMedian() {
        if (count % 2)
            return maxHeap.getTop() * 1.0;
        else
            return (maxHeap.getTop() + minHeap.getTop()) / 2.0;
        return 0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    MedianFinder medianFinder;
    medianFinder.addNum(1); // arr = [1]
    medianFinder.addNum(2); // arr = [1, 2]
    medianFinder.addNum(3);
    medianFinder.addNum(4);
    medianFinder.addNum(5);
    medianFinder.addNum(6);
    medianFinder.addNum(7);
    cout << medianFinder.findMedian() << endl;
    medianFinder.addNum(8);
    cout << medianFinder.findMedian() << endl;
}