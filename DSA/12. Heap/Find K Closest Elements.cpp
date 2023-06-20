class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq; // Priority queue to store the closest elements, sorted by absolute difference and element value

        // Iterate over each element in the array
        for(auto it : arr){
            pq.push({abs(it-x), it}); // Push the absolute difference and the element itself into the priority queue
            if(pq.size() > k) pq.pop(); // If the size of the priority queue exceeds k, remove the element with the largest absolute difference
        }

        vector<int> ans; // Vector to store the final k closest elements

        // Retrieve the elements from the priority queue
        while(!pq.empty()){
            ans.push_back(pq.top().second); // Add the element to the answer vector
            pq.pop(); // Remove the element from the priority queue
        }

        sort(ans.begin(), ans.end()); // Sort the answer vector in ascending order

        return ans; // Return the final k closest elements
    }
};
