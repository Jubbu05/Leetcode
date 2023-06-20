// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         int x = n-k;
//         vector<int> ans;
//         for(int i=0; i<=x; i++){
//             int maxi = nums[i];
//             for(int j=i; j<i+k; j++){
//                 maxi=max(nums[j], maxi);
//             }
//             ans.push_back(maxi);
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ans;
//         int n=nums.size();
//         //storing in decreasing order
//         deque <int> dq;
//         //visiting first subarray of size k
//         for(int i=0; i<k; i++)
//         {
//             while(!dq.empty() && dq.back()<nums[i]){
//                 dq.pop_back();
//             }
//             dq.push_back(nums[i]);
//         }
//         ans.push_back(dq.front());

//         for(int i=k; i<n; i++){
//             //remove element from previous window
//             if(dq.front()==nums[i-k])
//                 dq.pop_front();
//             while(!dq.empty() && dq.back()<nums[i]){
//                 dq.pop_back();
//             }
//             dq.push_back(nums[i]);
//             ans.push_back(dq.front());
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        //storing in decreasing order
        deque <int> q; //only indexes are stored
        for(int i=0; i<n; i++)
        {   
            //we are removing all the indexes which are out of 
            //i - k gives the out of window index
            if (!q.empty() && q.front() == i - k)
                q.pop_front(); //only window size of k is allowed
            
            //removes all element smaller than nums[i]
            while(!q.empty() && nums[q.back()]<nums[i])
                q.pop_back();
            
            q.push_back(i);//current index taken into deque

            //i>k-1 means we have visited first window
            if(i>=k-1)ans.push_back(nums[q.front()]); //front of deque is the max element
        }
        return ans;
    }
};
