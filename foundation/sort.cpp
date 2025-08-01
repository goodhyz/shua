#include <cassert>
#include <iostream>

using namespace std;

// 条件设置为p[j]>p[j+1] 则为升序
// 设置为p[j]<p[j+1] 则为降序
void bubbleSort(int *p, int n) {
    assert(p);
    for (int i = 0; i < n - 1; i++) {
        bool flag = true; // 小trick
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j] > p[j + 1]) {
                int tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
                flag = false;
            }
        }
        if (flag)
            break;
    }
}

// 升序insert p[j]>target
void insertSort(int *p, int n) {
    // n-1趟
    for (int i = 1; i < n; i++) {
        int target = p[i];
        int j = i - 1;
        while (j >= 0 && p[j] < target) {
            p[j + 1] = p[j];
            j--;
        }
        p[j + 1] = target;
    }
}

void shellSort(int *p, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int target = p[i];
            int j = i;
            while (j >= gap && p[j - gap] < target) {
                p[j] = p[j - gap];
                j -= gap;
            }
            p[j] = target;
        }
    }
}

void selectSort(int *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (p[min_idx] > p[j])
                min_idx = j;
        }
        int tmp = p[min_idx];
        p[min_idx] = p[i];
        p[i] = tmp;
    }
}

void selectSort1(int *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (p[max_idx] < p[j])
                max_idx = j;
        }
        int tmp = p[max_idx];
        p[max_idx] = p[i];
        p[i] = tmp;
    }
}

//构建大顶堆
void buildHeap(int*p,int n,int root){
    int left = 2*root+1;
    int right = 2*root+2;
    int max = root;
    if(right<n&&p[right]>p[max]){
        max = right;
    }
    if(left<n&&p[left]>p[max]){
        max = left;
    }
    if(max!=root){
        int tmp = p[root];
        p[root]=p[max];
        p[max]=tmp;
        buildHeap(p,n,max);
    }
}

// Hoare 写法
// 优化点：选择pivot时随机或者使用三数取中法
void quickSort(int*p,int l,int r){
    if(l>=r)return;
    int pi = p[r]; // 取右先动左，取左先动右
    // l r-1
    int left =l,right = r;
    while(left<right){
        while(left<right&&p[left]<=pi)left++; //找第一个大于pivot的元素 找不到left将达到right
        while(left<right&&p[right]>=pi)right--; // 找第一个小于pivot的元素 找不到right将达到left
        swap(p[left],p[right]); 
    }
    swap(p[r],p[left]); // 第一个
    quickSort(p,l,left-1);
    quickSort(p,left+1,r);
}

// 升序 使用大顶堆
void heapSort(int *p,int n){
    for(int i = (n-1-1)/2;i>=0;i--){
        buildHeap(p,n,i);
    }
    for(int i=0;i<n;i++){
        int tmp = p[0];
        p[0]=p[n-1-i];
        p[n-1-i]=tmp;
        buildHeap(p,n-1-i,0);
    }
}
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0,n-1);
    cout << "排序后的数组: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}