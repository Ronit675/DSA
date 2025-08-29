/*
 * Sliding Window Maximum Problem
 * 
 * Problem: Given an array of integers and a window size k, find the maximum element 
 * in each sliding window of size k as it moves from left to right.
 * 
 * Approach: Uses a priority queue (max heap) to efficiently track maximum elements.
 * - Store pairs of (element value, index) in the priority queue
 * - For each window position, add new element and remove elements outside current window
 * - The top of priority queue gives the maximum element in current window
 * 
 * Time Complexity: O(n log n) where n is the array size
 * Space Complexity: O(k) where k is the window size
 * 
 * Example: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 */

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      
      //define a priority queue that will store a pair of integers i.e. element, index
      priority_queue<pair<int, int>> pq;
      int n = nums.size()-1;

      //two pointers - first point at start and other after k elements
      //push elments between pointers in priority queue.
      int i = 0;
      int j = k-i-1;
      for(int a = i; a<=j; a++){
          pq.push({nums[a], a});
      }
      vector<int> ans;
      
      //push the first maximum element in ans array
      ans.push_back(pq.top().first);

      //start a loop for the pointers
      while(j<n){
        i++;
        j++;
        
        //push new element and its index
        pq.push({nums[j], j});

        //if the maximum element is out of range then perform pop opertaion
        //this will help in moving left pointer and the sliding window will keep moving.
        while(!pq.empty() && pq.top().second < i){
          pq.pop();
        }

        // when the while loop for poping is over then push the maximumu element in range i.e. pq.top()
        ans.push_back(pq.top().first);
      }
    return ans;
  }
};
