/*
 * Trapping Rain Water Problem
 * 
 * Problem: Given an array representing heights of bars, calculate how much rainwater 
 * can be trapped after it rains. Water can be trapped between bars if there are 
 * higher bars on both sides.
 * 
 * Approach: Two pointers technique with left and right maximum tracking
 * - Use two pointers (i, j) starting from both ends of the array
 * - Maintain leftmax and rightmax to track maximum heights seen so far
 * - Move the pointer with smaller height and calculate trapped water
 * - Water trapped at position = min(leftmax, rightmax) - current_height
 * 
 * Time Complexity: O(n) where n is the array size
 * Space Complexity: O(1) - only using constant extra space
 * 
 * Example: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6 (units of trapped water)
 */

#include <vector>
#include <algorithm>
using namespace std;

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
