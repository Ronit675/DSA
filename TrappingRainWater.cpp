class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftmax = 0;
        int rightmax = 0;
        int i = 0; 
        int j = n-1;
        int cnt = 0;
        while(i<j){
            if(height[i] <= height[j]){
                if(height[i] < leftmax){
                    cnt += min(leftmax, height[j]) - height[i];
                }
                else{
                    leftmax = height[i];
                }
                    i++;
            }
            else{
                if(height[j] < rightmax){
                    cnt+= min(rightmax, height[i]) - height[j];
                }
                else{
                    rightmax = height[j];
                }
                    j--;
            }
        }
        return cnt;
    }
};
