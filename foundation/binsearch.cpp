//参考

//https://blog.csdn.net/qq_45978890/article/details/116094046

#include<iostream>  

// 左闭右闭写法，必须加<= 
int search(int nums[], int size, int target) 
{
    int left = 0;
    int right = size - 1;	
    while (left <= right) {	
        int middle = left + ((right - left) / 2);
        if (nums[middle] > target) {
            right = middle - 1;
        } else if (nums[middle] < target) {
            left = middle + 1;
        } else {	
            return middle;
        }
    }
    //没有找到目标值
    return -1;
}

// 第一个大于等于x的数
int lower_bound(int nums[], int size, int target) 
{
    int l = 0, r = size - 1,mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] >= target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

// 最后一个小于等于x的数
int upper_bound(int nums[], int size, int target) 
{
    int l = 0, r = size - 1,mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] <= target) {
            l = mid + 1;
        } else if (nums[mid] > target) {
            r = mid - 1;
        }
    }
    return r;
}
int main(){
    int nums[] = {1, 3, 5, 7, 9};
    std::cout << upper_bound(nums, 5, 0);  // 返回 2（nums[2] = 5 ≤ 6）
}