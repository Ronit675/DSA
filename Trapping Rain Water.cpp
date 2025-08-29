class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        //left max and right max keeps track of maximum's of both ends.
        int leftmax = 0;
        int rightmax = 0;
        
        //moving pointers
        int i = 0; 
        int j = n-1;

        //count of trapping water
        int cnt = 0;

        while(i<j){

            //comparing heights first and then compare maximum according to the pointer.
            //if left pointer is smaller then again compare with leftmax.
            //if leftmax is smaller then count else assign new leftmax.
            if(height[i] <= height[j]){
                if(height[i] < leftmax){
                    cnt += min(leftmax, height[j]) - height[i];
                }
                else{
                    leftmax = height[i];
                }
                i++;
            }
            //if right pointer is smaller then again compare with rightmax.
            //if rightmax is smaller then count else assign new rightmax.
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
