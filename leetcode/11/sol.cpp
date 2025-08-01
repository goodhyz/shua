class Solution {
    public:
        int maxArea(vector<int>& height) {
            int left = 0, right = height.size() - 1;
            int max_area = min(height[left],height[right])*(right-left);
            while(left<right){
                if(height[left]>=height[right]){
                    right--;
                }else{
                    left++;
                }
                
                max_area = max(max_area,min(height[left],height[right])*(right-left));
            }
            return max_area;
        }
    };