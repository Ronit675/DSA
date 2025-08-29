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
